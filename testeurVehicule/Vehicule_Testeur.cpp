/**
 * \file Vehicule_Testeur.cpp
 * \brief Implantation des tests uniteur de la classe abstraite Vehicule
 * \date 2019-11-09
 * \author: Dany Pepin
 */


#include <gtest/gtest.h>
#include "Vehicule.h"
using namespace saaq;
using namespace std;

/**
 * \class Vehicule_Testeur
 * \brief classe de test qui permet de tester la classe abstraite Vehicule
 */

class VehiculeDeTest: public Vehicule
{
public:
	VehiculeDeTest(const std::string& p_niv, const std::string& p_immatriculation):
		Vehicule(p_niv, p_immatriculation)
	{
	}
	;
	virtual Vehicule* clone() const
	{
		return new VehiculeDeTest(*this);
	}
	;
	virtual std::string reqVehiculeFormate() const
	{
		std::ostringstream os;
		os << Vehicule::reqVehiculeFormate();
		return os.str();
	}
	;
	virtual double tarificationAnnuelle() const
	{
		return 0;
	}

};

/**
 * \brief Test du constructeur Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
 * 		cas valide : Creation d'un objet Vehicule et verification de l'assignation des attributs de l'objet Vehicule
 * 		cas invalides: a completer
 *
 */

TEST(Vehicule, ConstructeurAvecParametres)
{
	VehiculeDeTest VehiculeTest("3VWFE21C04M000001", "IFT 006");
	ASSERT_EQ("3VWFE21C04M000001", VehiculeTest.reqNiv());
	ASSERT_EQ("IFT 006", VehiculeTest.reqImmatriculation());
}

// cas invalide


/**
 * \brief Fixture UnVehicule pour les methode publiques de la classe de test
 */
class UnVehicule: public ::testing::Test
{
public:
	UnVehicule() :
		unVehicule("3VWFE21C04M000001", "IFT 006")
	{
	}
	;
	VehiculeDeTest unVehicule;



};

/**
 * \brief Test de la methode reqNiv()
 * 		Cas valide : verifier le retour du niv du vehicule
 * 		Cas invalide: aucun identifier
 */

TEST_F(UnVehicule, reqNiv)
{
	ASSERT_EQ("3VWFE21C04M000001", unVehicule.reqNiv());
}

/**
 * \brief Test de la methode reqImmatriculation()
 * 		Cas valide: verifier le retour de l'immatriculation du vehicule
 * 		Cas invalide: aucun identifier
 */

TEST_F(UnVehicule, reqImmatriculation)
{
	ASSERT_EQ("IFT 006", unVehicule.reqImmatriculation());
}

/**
 * \brief Test de la methode bool operator==(const Vehicule& p_vehicule) const;
 * 		Cas valide: verifier le retour des informations sur l'objet Vehicule formater
 * 		Cas invalide: aucun
 */

TEST_F(UnVehicule, reqVehiculeFormate)
{
	util::Date uneDate;
	std::ostringstream os;
	os << "Numero de serie : " << unVehicule.reqNiv() << std::endl
	<< "Numero d'immatriculation : " << unVehicule.reqImmatriculation() << std::endl
	<< "Date d'enregistrement : " << uneDate.reqDateFormatee()<< std::endl;
	ASSERT_EQ(os.str(), unVehicule.reqVehiculeFormate());
}

