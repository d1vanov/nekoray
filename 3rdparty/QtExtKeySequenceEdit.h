#pragma once

#include <QKeySequenceEdit>

class QtExtKeySequenceEdit : public QKeySequenceEdit
{
    Q_OBJECT
public:
    explicit QtExtKeySequenceEdit(QWidget *parent);

    ~QtExtKeySequenceEdit() override;

protected:
    void keyPressEvent(QKeyEvent *pEvent) override;
};
