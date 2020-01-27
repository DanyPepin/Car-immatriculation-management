/**
 * \file Proprietaire_Testeur.cpp
 * \brief Test unitaire de la classe Proprietaire
 * \date 2019-11-09
 * \author: Dany Pepin
 */


#include <gtest/gtest.h>
#include "Vehicule.h"
#include "Proprietaire.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Date.h"
#include "VehiculeException.h"
using namespace saaq;
using namespace std;

/**
 * \brief Test du constructeur Proprietaire(const std::string& p_nom, const std::string& p_prenom)
 * 		Cas valide : Creation d'un objet Proprietaire et verification de l'assignation de ses attributs
 * 		Cas invalide:
 * 					le nom du proprietaire ne doit pas etre vide
 * 					le prenom du proprietaire ne doit pas etre vide
 */

TEST(Proprietaire, ConstructeurAvecParametresValide)
{
	Proprietaire ProprietaireTest("Pepin", "Dany");
	ASSERT_EQ("Pepin", ProprietaireTest.reqNom());
	ASSERT_EQ("Dany", ProprietaireTest.reqPrenom());
}
//cas invalide

TEST(Proprietaire, ConstructeurAvecNomInvalide)
{
	ASSERT_THROW(Proprietaire ProprietaireTest("", "Dany");,PreconditionException);
}

TEST(Proprietaire, ConstructeurAvecPrenomInvalide)
{
	ASSERT_THROW(Proprietaire ProprietaireTest("Pepin", "");,PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la classe test
 */
class UnProprietaire: public ::testing::Test
{
public:
	UnProprietaire() : unProprietaire("Pepin", "Dany")
{}
;
	Proprietaire unProprietaire;
};

/**
 * \brief Test de la methode reqNom()
 * 		Cas valide: verifier le retour du Proprietaire
 * 		Cas invalide: aucun d'identifier
 */
TEST_F(UnProprietaire, reqNom)
{
	ASSERT_EQ("Pepin", unProprietaire.reqNom());
}
/**
 * \brief Test de la methode reqPrenom()
 * 		Cas valide: verifier le retour du Proprietaire
 * 		Cas invalide: aucun d'identifier
 */
TEST_F(UnProprietaire, reqPrenom)
{
	ASSERT_EQ("Dany", unProprietaire.reqPrenom());
}

/**
 * \brief Test de la methode std::string reqProprietaireFormate()
 * 		Cas valide: verifier le retour des informations dans l'objet Proprietaire
 * 		Cas invalide : aucun d'identifier
 */
TEST_F(UnProprietaire, reqProprietaireFormate)
{
	cout << unProprietaire.reqProprietaireFormate();
	util::Date uneDate;
	VehiculePromenade unVehiculePromenade("3VWFE21C04M000001", "A00 ABC", 4);
	Camion unCamion("3VWFE21C04M000001", "L000000", 3005, 2);
	unProprietaire.ajouterVehicule(unVehiculePromenade);
	unProprietaire.ajouterVehicule(unCamion);
	std::ostringstream os;
	os << "Proprietaire" << std::endl
		<< "-------------------" << std::endl
		<< "Nom     :  " << unProprietaire.reqNom() << std::endl
		<< "Prenom  :  " << unProprietaire.reqPrenom() << std::endl
		<< "-------------------" << std::endl
		<< "Numero de serie : " << unVehiculePromenade.reqNiv()<< std::endl
		<< "Numero d'immatriculation : " << unVehiculePromenade.reqImmatriculation() << std::endl
		<< "Date d'enregistrement : " << uneDate.reqDateFormatee() << std::endl
		<< "Nombre de places: " << unVehiculePromenade.reqNbPlaces() << std::endl
		<< "tarif: " << unVehiculePromenade.tarificationAnnuelle()<<"$" <<  endl
		<< "-------------------" << std::endl
		<< "Numero de serie : " << unCamion.reqNiv()<< std::endl
		<< "Numero d'immatriculation : " << unCamion.reqImmatriculation() << std::endl
		<< "Date d'enregistrement : " << uneDate.reqDateFormatee() << std::endl
		<< "Nombre de places: " << unVehiculePromenade.reqNbPlaces() << std::endl
		<< "tarif: " << unVehiculePromenade.tarificationAnnuelle()<<"$" <<  endl;
	ASSERT_EQ(os.str(), unProprietaire.reqProprietaireFormate());
}

/**
 * \brief Test de la methode ajouterVehicule(const Vehicule& p_nouveauVehicule)
 * 			Cas valide : on vient verifier si le vehicule a bien ete ajouter
 * 			Cas invalide: aucun d'identifier
 */
TEST_F(UnProprietaire, ajouterVehicule)
{
	VehiculePromenade unVehiculePromenade("3VWFE21C04M000001", "A00 ABC", 4);
	unProprietaire.ajouterVehicule(unVehiculePromenade);
	util::Date uneDate;
	ostringstream os;
	os << "Proprietaire" << std::endl
		<< "-------------------" << std::endl
		<< "Nom     :  " << unProprietaire.reqNom() << std::endl
		<< "Prenom  :  " << unProprietaire.reqPrenom() << std::endl
		<< "-------------------" << std::endl
		<< "Numero de serie : " << unVehiculePromenade.reqNiv()<< std::endl
		<< "Numero d'immatriculation : " << unVehiculePromenade.reqImmatriculation() << std::endl
		<< "Date d'enregistrement : " << uneDate.reqDateFormatee() << std::endl
		<< "Nombre de places: " << unVehiculePromenade.reqNbPlaces() << std::endl
		<< "tarif: " << unVehiculePromenade.tarificationAnnuelle()<<"$" <<  endl
		<< "-------------------" << std::endl;
}

/**
 * \brief Test de VehiculeEstDejaPresent, on verifie si
 * on a une erreur quand on essaye d'ajouter 2 fois le meme vehicule
 */
TEST(Proprietaire, VehiculeEstDejaPresent)
{
	Proprietaire proprietaireTest("Pepin", "Dany");
	VehiculePromenade testF("3VWFE21C04M000001", "A00 ABC", 4);
	VehiculePromenade vehiculeFtest("3VWFE21C04M000001", "A00 ABC", 4);
	proprietaireTest.ajouterVehicule(testF);

	ASSERT_THROW(proprietaireTest.ajouterVehicule(vehiculeFtest);, PreconditionException);

}

/**
 * \brief Test pour la methode supprimerVehicule cas valide ( n;est pas absent)
 */
TEST(Proprietaire, supprimerVehiculeValide)
{
	Proprietaire proprietaireTest("Pepin", "Dany");
	VehiculePromenade testF("3VWFE21C04M000001", "A00 ABC", 4);
	proprietaireTest.ajouterVehicule(testF);

	ASSERT_THROW(proprietaireTest.supprimerVehicule("3VWFE21C04M000001");, PreconditionException);
}

/**
 * \brief Test pour supprimerVehicule invalide (donc on tente de supprimer un vehicule absent)
 */

TEST(Proprietaire, supprimerVehiculeAbsent)
{
	Proprietaire proprietaireTest("Pepin", "Dany");
	VehiculePromenade testF("3VWFE21C04M000001", "A00 ABC", 4);
	proprietaireTest.ajouterVehicule(testF);

	ASSERT_THROW(proprietaireTest.supprimerVehicule("3VWFE21C04M000001222");, PreconditionException);

}
