#include "gestionproprietairegui.h"
#include "camionqt.h"
#include "supprimerqt.h"
#include "vehiculepromenadeqt.h"
#include <iostream>
#include <string>
#include "Proprietaire.h"
#include"VehiculeException.h"
using namespace std;
using namespace util;
using namespace saaq;
Proprietaire leProp("Tremblay", "Louis");
GestionProprietaireGui::GestionProprietaireGui(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	//QObject::connect(ui.actionCamion2,SIGNAL(triggered()), this, SLOT(ajoutCamion()));
}

GestionProprietaireGui::~GestionProprietaireGui()
{
	leProp.~Proprietaire();
}
void GestionProprietaireGui::ajouterCamion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux){
	Camion monCamion= Camion(p_niv, p_immatriculation, p_poids, p_nbEssieux);
	leProp.ajouterVehicule(monCamion);

}

void GestionProprietaireGui::ajouterVehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces){
	VehiculePromenade monVehiculePromenade= VehiculePromenade(p_niv, p_immatriculation, p_nbPlaces);
	leProp.ajouterVehicule(monVehiculePromenade);

}
void GestionProprietaireGui::suprimerVehicul(const std::string& p_niv){
	leProp.saaq::Proprietaire::supprimerVehicule(p_niv);
}

void GestionProprietaireGui::dialogAjoutVpromenade(){
	//VehiculePromenadeQt
	VehiculePromenadeQt valideSaisieVP(this);
	if(valideSaisieVP.exec()){
		try{
			ajouterVehiculePromenade(valideSaisieVP.reqNiv().toStdString(),// EFFECTUER les conversion car la methode ajouter
					valideSaisieVP.reqImmatriculation().toStdString(),
					valideSaisieVP.reqNbPlaces().toInt());
					ui.textBrowser-> setText(leProp.reqProprietaireFormate().c_str());

		}catch(VehiculeDejaPresentException& e){
			QString message(e.what());
			QMessageBox::information(this,"Le Vehicule existe deja veuillez saisir a nouveau!",message);}
	}
}

void GestionProprietaireGui::dialogAjoutCamion(){
	// pour poper le dialogue
	CamionQt valideSaisie(this);
	if(valideSaisie.exec()){
		try{
			ajouterCamion(valideSaisie.reqNiv().toStdString(),// EFFECTUER les conversion car la methode ajouter
					valideSaisie.reqImmatriculation().toStdString(),
					valideSaisie.reqPoids().toInt(),
					valideSaisie.reqNbEssieux().toInt());
			ui.textBrowser-> setText(leProp.reqProprietaireFormate().c_str());

		}catch(VehiculeDejaPresentException& e){
			QString message(e.what());
			QMessageBox::information(this,"Le Vehicule existe deja veuillez saisir a nouveau!",message);}
	}

}
void GestionProprietaireGui::dialogSuprimerVehicule()
{
	SupprimerQt valideSaisieNiv(this);
	if(valideSaisieNiv.exec()){
		try{
			if (QMessageBox::Yes ==QMessageBox(QMessageBox::Information,
					"supprimer","vous voulez vraiment supprimer ce vehicule",
					QMessageBox::Yes|QMessageBox::No).exec())
			{

			suprimerVehicul(valideSaisieNiv.reqNiv().toStdString());
			ui.textBrowser-> setText(leProp.reqProprietaireFormate().c_str());
			}
		}catch(VehiculeAbsentException& e){
			QString message(e.what());
			QMessageBox::information(this,"Le Vehicule n'existe pas!",message);
		}
	}
}

