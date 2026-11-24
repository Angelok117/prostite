#include "cardwindow.h"
#include <QLabel>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QIcon>
#include <QPushButton>

CardWindow::CardWindow(const QString &surname, const QString &name,
    int age, const QString &city, QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(400, 260);
    setWindowTitle("Карточка участника");
    setWindowIcon(QIcon(":/img/00.png"));

    QLabel* label_surname = new QLabel("Фамилия:", this);
    QLabel* value_surname = new QLabel(surname, this);
    QLabel* label_name = new QLabel("Имя:", this);
    QLabel* value_name = new QLabel(name, this);
    QLabel* label_age = new QLabel("Возраст:", this);
    QLabel* value_age = new QLabel(QString::number(age), this);
    QLabel* label_city = new QLabel("Город:", this);
    QLabel* value_city = new QLabel(city, this);

    QGridLayout* layout_card = new QGridLayout;
    layout_card->setHorizontalSpacing(12);
    layout_card->setVerticalSpacing(12);
    layout_card->addWidget(label_surname, 0, 0);
    layout_card->addWidget(value_surname, 0, 1);
    layout_card->addWidget(label_name, 1, 0);
    layout_card->addWidget(value_name, 1, 1);
    layout_card->addWidget(label_age, 2, 0);
    layout_card->addWidget(value_age, 2, 1);
    layout_card->addWidget(label_city, 3, 0);
    layout_card->addWidget(value_city, 3, 1);

    QPushButton* button_close = new QPushButton("Закрыть", this);

    QVBoxLayout* layout_main = new QVBoxLayout(this);
    layout_main->setContentsMargins(40, 30, 40, 30);
    layout_main->addLayout(layout_card);
    layout_main->addStretch();
    layout_main->addWidget(button_close, 0, Qt::AlignCenter);

    connect(button_close, &QPushButton::clicked, this, &QDialog::accept);
}

CardWindow::~CardWindow() = default;
