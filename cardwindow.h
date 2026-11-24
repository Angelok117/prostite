#ifndef CARDWINDOW_H
#define CARDWINDOW_H

#include <QDialog>

class CardWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CardWindow(const QString &surname, const QString &name,
        int age, const QString &city, QWidget *parent = nullptr);
    ~CardWindow() override;
};
#endif
