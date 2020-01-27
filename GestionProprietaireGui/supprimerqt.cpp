#include "supprimerqt.h"
using namespace util;
SupprimerQt::SupprimerQt(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

SupprimerQt::~SupprimerQt()
{

}
QString SupprimerQt::reqNiv() const{
	return (ui.lineEdit_NIV->text());
}
void SupprimerQt::valideSaisieNIV(){
	if(!validerNiv(reqNiv().toStdString())){
			QString probleme("Le Numéro de serie saisie n'est pas Bon!");
			QMessageBox::information(this, "Erreur!",probleme);
			return;
		}
	accept();
}
