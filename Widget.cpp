#include "Widget.h"
#include "ui_Widget.h"
#include "DuDoubleItemDelegate.h"
#include "SolveForm.h"
#include <QMenu>
#include <QVBoxLayout>
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mDelegate = new DuDoubleItemDelegate(this);
    mModel = new QStandardItemModel(this);
    mSolver = new SolveForm(this);
    mMenu = new QMenu("Resolver", this);
    mLayout = new QVBoxLayout;

    ui->tableView->setModel(mModel);
    ui->tableView->setItemDelegate(mDelegate);
    mLayout->addWidget(mSolver);
    mMenu->setLayout(mLayout);
    ui->resolverPushButton->setMenu(mMenu);
}

Widget::~Widget()
{
    delete ui;
}

QStandardItemModel *Widget::model() const
{
    return mModel;
}

QSpinBox *Widget::nVars() const
{
    return ui->numeroIncognitasSpinBox;
}

void Widget::on_numeroIncognitasSpinBox_valueChanged(int arg1)
{
    mModel->clear();
    mModel->setColumnCount(arg1 + 1);
    mModel->setRowCount(arg1);
    QStringList labels;
    for (int i = 0; i < arg1; ++i) {
        labels << QString("x%1").arg(i + 1);
    }
    labels << "TI";
    mModel->setHorizontalHeaderLabels(labels);
}

