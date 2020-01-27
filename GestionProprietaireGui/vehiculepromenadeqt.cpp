#include "vehiculepromenadeqt.h"
#include<string>
using namespace util;
VehiculePromenadeQt::VehiculePromenadeQt(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
}

VehiculePromenadeQt::~VehiculePromenadeQt()
{

}


QString VehiculePromenadeQt::reqNiv() const{
	return (ui.lineEdit_NIV->text());
}
QString VehiculePromenadeQt::reqImmatriculation() const
{
	return (ui.lineEdit_Immatriculation->text());}

QString VehiculePromenadeQt::reqNbPlaces() const{
	return (ui.lineEdit_NbPlaces->text());
}


void VehiculePromenadeQt::valideSaisieVP(){
	if(!validerNiv(reqNiv().toStdString())){
		QString probleme("Le Numéro de série saisie n'est pas Bon!");
		QMessageBox::information(this, "Erreur!",probleme);
		return;
	}
	if(!validationImmatriculationPromenade(reqImmatriculation().toStdString())){
		QString message("Le matricule n'est pas dans le bon Format!");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if(reqNbPlaces().toInt()<=0){
		QString message("le nombre d'éssieux doit être supérieur a zero");
		QMessageBox::information(this, "Erreur!", message);
		return;}
	accept();
}
