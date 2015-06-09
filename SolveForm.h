#ifndef SOLVEFORM_H
#define SOLVEFORM_H

#include <QWidget>

namespace Ui
{
class SolveForm;
}

class Widget;

class SolveForm : public QWidget
{
    Q_OBJECT
public:
    explicit SolveForm(QWidget *parent = nullptr);
    ~SolveForm();
private slots:
    void on_resolverPushButton_clicked();
private:
    Ui::SolveForm *ui;
    Widget *mParent;
};

#endif // SOLVEFORM_H
