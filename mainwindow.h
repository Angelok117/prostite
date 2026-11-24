#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QSpinBox;
class QComboBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void showCard();
    void clearForm();

private:
    QLineEdit* line_surname;
    QLineEdit* line_name;
    QSpinBox* spin_age;
    QComboBox* combo_city;
};
#endif
