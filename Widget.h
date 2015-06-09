#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class DuDoubleItemDelegate;
class QStandardItemModel;
class SolveForm;
class QMenu;
class QVBoxLayout;
class QSpinBox;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QStandardItemModel *model() const;
    QSpinBox *nVars() const;
private slots:
    void on_numeroIncognitasSpinBox_valueChanged(int arg1);
private:
    Ui::Widget *ui;
    DuDoubleItemDelegate *mDelegate;
    QStandardItemModel *mModel;
    SolveForm *mSolver;
    QMenu *mMenu;
    QVBoxLayout *mLayout;
};

#endif // WIDGET_H
