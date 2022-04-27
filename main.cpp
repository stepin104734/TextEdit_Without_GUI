#include "mainwindow.h"

#include "QWidget"
#include "QGridLayout"
#include "QVBoxLayout"

#include "QLabel"
#include "QLineEdit"

#include "QObject"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //created mainwindow
    QWidget *window = new QWidget;

    //created layouts
    QGridLayout *g_layout = new QGridLayout;
    QVBoxLayout *v_layout = new QVBoxLayout;

    //created a label and a line edit
    QLineEdit *m_le_1 = new QLineEdit("");
    QLabel *m_label_1 = new QLabel("");

    //lets add sytle sheet to line edit and label
    m_le_1->setStyleSheet(""); //let it be default
    m_label_1->setStyleSheet("color:white; background-color:black");

    //lets add attributes to our widgets
    m_le_1->setClearButtonEnabled(1);
    m_le_1->setPlaceholderText("Enter your text here");
    m_label_1->setAlignment(Qt::AlignCenter);

    //lets set vertical layout for both line edit and label
    v_layout->addWidget(m_le_1);
    v_layout->addWidget(m_label_1);

    //lets format our layout
    window->setLayout(g_layout);
    g_layout->addLayout(v_layout,1,1);

    QObject::connect(m_le_1, SIGNAL(textChanged(QString)),m_label_1, SLOT(setText(QString)));

    //show out application in gui
    window->show();

    return a.exec();
}
