#include "camionqt.h"
#include <string>

#include <QMessageBox>
#include "Camion.h"
using namespace util;
using namespace std;
using namespace saaq;
CamionQt::CamionQt(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	//QObject::connect(ui.pushButton,SIGNAL(clicked()),this, SLOT(valideSaisie()));

}

CamionQt::~CamionQt()
{}

QString CamionQt::reqNiv() const{
	return (ui.NIV->text());//donne acces au champs a texte de ui
}
QString CamionQt::reqImmatriculation () const {
	return (ui.Imm->text()); // c est du texte quand saisie de type QString
}
QString CamionQt::reqPoids() const{
	return (ui.Poid->text());
}
QString CamionQt::reqNbEssieux() const{
	return (ui.nbEss->text());
}

void CamionQt::valideSaisie(){
	//programmer les enregistrement
	if(!validerNiv(reqNiv().toStdString())){

		QString probleme("Le Numéro de série saisie n'est pas Bon!");
		QMessageBox::information(this, "Erreur!",probleme);
		return;
	}
	if(!validationImmatriculationCamion(reqImmatriculation().toStdString())){
		QString message("Le matricule n'est pas dans le bon Format!");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if(reqPoids().toInt() < 3000){
		QString message("Le poid doit être supérieur à 3000 kg!");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}

	if(reqNbEssieux().toInt()<=2){
		QString message("le nombre d'éssieux doit être supérieur ou égal à 2!");
		QMessageBox::information(this, "Erreur!", message);
		return;}

	accept();
}


