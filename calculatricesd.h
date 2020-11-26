#ifndef CALCULATRICESD_H
#define CALCULATRICESD_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QScriptEngine>
#include <QList>
#include <QListWidget>

#define NBTOUCHES 20

QT_BEGIN_NAMESPACE
namespace Ui { class calculatricesd; }
QT_END_NAMESPACE

class calculatricesd : public QWidget
{
    Q_OBJECT

public:
    calculatricesd(QWidget *parent = nullptr);
    ~calculatricesd();

private:
    Ui::calculatricesd *ui;
    QString tablesDesSyboles[NBTOUCHES]={"0","1","2","3","4","5","6","7","8","9","c","=","/","*","-","+","(",")"," "," "};
    QGridLayout *grille;
    QLineEdit *afficheur;
    QListWidget *historique;
    QPushButton *touches[NBTOUCHES];
private slots:
    void onQPushButtonClicked();
};
#endif // CALCULATRICESD_H
