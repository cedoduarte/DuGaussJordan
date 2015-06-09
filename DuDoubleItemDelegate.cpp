#include "DuDoubleItemDelegate.h"
#include <QDoubleSpinBox>

DuDoubleItemDelegate::DuDoubleItemDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *DuDoubleItemDelegate::createEditor(QWidget *parent,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    (void) option;
    (void) index;
    auto doubleSpinBox = new QDoubleSpinBox(parent);
    doubleSpinBox->setMaximum(99999999999.999999999);
    doubleSpinBox->setMinimum(-doubleSpinBox->maximum());
    return doubleSpinBox;
}

void DuDoubleItemDelegate::setEditorData(QWidget *editor,
                                         const QModelIndex &index) const
{
    auto doubleSpinBox = static_cast<QDoubleSpinBox *>(editor);
    doubleSpinBox->setValue(index.data().toDouble());
}

void DuDoubleItemDelegate::setModelData(QWidget *editor,
                                        QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    auto doubleSpinBox = static_cast<QDoubleSpinBox *>(editor);
    model->setData(index, doubleSpinBox->value());
}

void DuDoubleItemDelegate::updateEditorGeometry(QWidget *editor,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const
{
    (void) index;
    editor->setGeometry(option.rect);
}

