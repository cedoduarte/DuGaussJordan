#ifndef DUDOUBLEITEMDELEGATE_H
#define DUDOUBLEITEMDELEGATE_H

#include <QItemDelegate>

class DuDoubleItemDelegate : public QItemDelegate
{
public:
    DuDoubleItemDelegate(QObject *parent = nullptr);
protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

#endif // DUDOUBLEITEMDELEGATE_H
