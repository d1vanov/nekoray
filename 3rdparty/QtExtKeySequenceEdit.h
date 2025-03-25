#pragma once

#include <QKeySequenceEdit>

class QtExtKeySequenceEdit : public QKeySequenceEdit {
public:
    explicit QtExtKeySequenceEdit(QWidget *parent);

    ~QtExtKeySequenceEdit() override;

protected:
    void keyPressEvent(QKeyEvent *pEvent) override;
};
