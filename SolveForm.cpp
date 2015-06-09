#include "SolveForm.h"
#include "ui_SolveForm.h"
#include "DuGaussJordan.h"
#include "Widget.h"
#include <QSpinBox>
#include <QStandardItemModel>

SolveForm::SolveForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SolveForm)
{
    ui->setupUi(this);
    mParent = static_cast<Widget *>(parent);
    setMaximumSize(size());
    setMinimumSize(size());
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({ "x", "TI" });
}

SolveForm::~SolveForm()
{
    delete ui;
}

void SolveForm::on_resolverPushButton_clicked()
{
    DuGaussJordan cGaussJordan;
    DuMatrix matrix;
    const int var = mParent->nVars()->value();
    matrix.resize(var + 1);
    for (auto &ix : matrix) {
        ix.resize(var + 1);
    }
    for (int i = 0; i < var; ++i) {
        for (int k = 0; k < var + 1; ++k) {
            auto item = mParent->model()->item(i, k);
            if (item != nullptr) {
                matrix[i][k] = item->text().toDouble();
            }
        }
    }
    ui->tableWidget->setRowCount(0);
    auto results = cGaussJordan.solve(matrix, var);
    for (const auto &x : results) {
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0,
                    new QTableWidgetItem(QString("x%1").arg(row + 1)));
        ui->tableWidget->setItem(row, 1,
                    new QTableWidgetItem(QString::number(x)));
    }
}
