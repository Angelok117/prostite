#include "mainwindow.h"
#include "cardwindow.h"
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(520, 320);
    setWindowTitle("Анкета участника");
    setWindowIcon(QIcon(":/img/00.png"));

    QMenu* menu_file = menuBar()->addMenu("Файл");
    QAction* action_card = menu_file->addAction("Показать карточку");
    QAction* action_exit = menu_file->addAction("Выход");

    QWidget* widget_center = new QWidget(this);
    setCentralWidget(widget_center);

    QLabel* label_surname = new QLabel("Фамилия:", widget_center);
    line_surname = new QLineEdit(widget_center);
    line_surname->setPlaceholderText("Введите свою фамилию");
    QLabel* label_name = new QLabel("Имя:", widget_center);
    line_name = new QLineEdit(widget_center);
    line_name->setPlaceholderText("Введите свое имя");
    QLabel* label_age = new QLabel("Возраст:", widget_center);
    spin_age = new QSpinBox(widget_center);
    spin_age->setRange(1, 100);
    QLabel* label_city = new QLabel("Город:", widget_center);
    combo_city = new QComboBox(widget_center);
    combo_city->addItems({"Москва", "Санкт-Петербург", "Тамбов", "Самара", "Париж"});

    QFormLayout* layout_form = new QFormLayout;
    layout_form->addRow(label_surname, line_surname);
    layout_form->addRow(label_name, line_name);
    layout_form->addRow(label_age, spin_age);
    layout_form->addRow(label_city, combo_city);

    QPushButton* button_card = new QPushButton("Показать карточку", widget_center);
    QPushButton* button_clear = new QPushButton("Очистить", widget_center);
    QHBoxLayout* layout_buttons = new QHBoxLayout;
    layout_buttons->addWidget(button_card);
    layout_buttons->addWidget(button_clear);

    QVBoxLayout* layout_main = new QVBoxLayout(widget_center);
    layout_main->setContentsMargins(40, 30, 40, 30);
    layout_main->setSpacing(12);
    layout_main->addLayout(layout_form);
    layout_main->addStretch();
    layout_main->addLayout(layout_buttons);

    connect(button_card, &QPushButton::clicked, this, &MainWindow::showCard);
    connect(action_card, &QAction::triggered, this, &MainWindow::showCard);
    connect(button_clear, &QPushButton::clicked, this, &MainWindow::clearForm);
    connect(action_exit, &QAction::triggered, this, &QWidget::close);
}

MainWindow::~MainWindow() = default;

void MainWindow::showCard()
{
    CardWindow card(line_surname->text(), line_name->text(),
        spin_age->value(), combo_city->currentText(), this);
    card.exec();
}

void MainWindow::clearForm()
{
    line_surname->clear();
    line_name->clear();
    spin_age->setValue(spin_age->minimum());
    combo_city->setCurrentIndex(0);
}
