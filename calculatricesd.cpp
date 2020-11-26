#include "calculatricesd.h"
#include "ui_calculatricesd.h"

calculatricesd::calculatricesd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calculatricesd)
{
    ui->setupUi(this);
    int colonne=0, ligne=0;
    grille=new QGridLayout(this);
    afficheur=new QLineEdit(this);
    historique=new QListWidget(this);
    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    grille->addWidget(afficheur,ligne,colonne,1,5);//(y,x,rowspan,colspan)
    grille->addWidget(historique,1,4,5,1);//(y,x,rowspan,colspan)

    for(int i=0;i<NBTOUCHES;i++){
        touches[i]=new QPushButton;
        touches[i]->setText(tablesDesSyboles[i]);
        touches[i]->setMaximumWidth(80);
        touches[i]->setMinimumHeight(80);
        grille->addWidget(touches[i],i/4+1,i%4);
        connect(touches[i],&QPushButton::clicked,this,&calculatricesd::onQPushButtonClicked);
    }
}

calculatricesd::~calculatricesd()
{
    delete ui;
    delete  grille;
    delete  afficheur;
    delete  historique;

}

void calculatricesd::onQPushButtonClicked()
{
    QPushButton *touche;
    QScriptEngine unCalcul;
    QScriptValue result;
    touche=qobject_cast<QPushButton*>(sender());
    if(touche->text() != "=" && touche->text() != "c"){
        afficheur->insert(touche->text());


    }
    else{
        if(touche->text() == "="){
           historique->addItem(afficheur->text()+"=");
           result = unCalcul.evaluate(afficheur->text());
           afficheur->setText(result.toString());

           historique->addItem(result.toString());
        }
        else{
            afficheur->setText("");

        }
    }
}

