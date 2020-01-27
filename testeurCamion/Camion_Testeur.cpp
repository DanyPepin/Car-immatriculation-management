/**
 * \file Camion_Testeur.cpp
 * \brief Test unitaire de la classe Camion
 * \date 2019-11-09
 * \author: Dany Pepin
 */

#include <gtest/gtest.h>
#include "Camion.h"

using namespace saaq;
using namespace std;

/**
 * \brief Test du constructeur Camion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux);
 * 		Cas valide: Creation d'un objet Camion et verification de l'assignation des attributs de l'objet
 * 		Cas invalide:
 * 				poids <= 3000 kg
 * 				nombre d'essieux < 2
 */

TEST(Camion, ConstructeurAvecParametres)
{
	Camion CamionTest("3VWFE21C04M000001", "L000000", 3005, 2);
	ASSERT_EQ("3VWFE21C04M000001", CamionTest.reqNiv());
	ASSERT_EQ("L000000", CamionTest.reqImmatriculation());
	ASSERT_EQ(3005, CamionTest.reqPoids());
	ASSERT_EQ(2, CamionTest.reqNbEssieux());

}

//cas invalides


TEST(Camion, ConstructeurPoidsInvalide)
{
	ASSERT_THROW(Camion CamionTest("3VWFE21C04M000001","L000000", 2900, 2);,PreconditionException);
}

TEST(Camion, ConstructeurNbEssieuxInvalide)
{
	ASSERT_THROW(Camion CamionTest("3VWFE21C04M000001","L000000", 3005, 1);,PreconditionException);
}

/**
 * \brief Creation d'une fixture pour les methode public de la classe de test
 */

class UnCamion: public ::testing::Test
{
public:
	UnCamion():
		unCamion("3VWFE21C04M000001", "L000000", 3005, 2)
	{
	}
	;
	Camion unCamion;
};

/**
 * \brief test de la methode reqPoids
 * 		Cas valide : verifier le retour du poids du camion
 * 		Cas invalide : aucun
 */
TEST_F(UnCamion, reqPoids)
{
	ASSERT_EQ(3005, unCamion.reqPoids());
}

TEST_F(UnCamion, reqNbEssieux)
{
	ASSERT_EQ(2, unCamion.reqNbEssieux());
}

/**
 * \brief Test de la methode std::string saaq::Camion::reqVehiculeFormate() const
 * 		Cas valide: verifier le retour des info de l'objet Camion formater
 * 		Cas invalide : aucun
 */
TEST_F(UnCamion, reqVehiculeFormate)
{
	util::Date uneDate;
	std::ostringstream os;
	os << "Numero de serie : " << unCamion.reqNiv() << std::endl
	<< "Numero d'immatriculation : " << unCamion.reqImmatriculation() << std::endl
	<< "Date d'enregistrement : " << uneDate.reqDateFormatee()<< std::endl
	<< "Nombre d'essieux: " << unCamion.reqNbEssieux() << std::endl
	<< "poids: " << unCamion.reqPoids() << "kg" << std::endl
	<< "tarif: " << unCamion.tarificationAnnuelle() <<"$" <<  std::endl;
	ASSERT_EQ(os.str(), unCamion.reqVehiculeFormate());
}
