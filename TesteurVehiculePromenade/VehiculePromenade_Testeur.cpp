/**
 * \file VehiculePromenade_Testeur.cpp
 * \brief Test unitaire de la classe VehiculePromenade
 * \date 2019-11-09
 * \author: Dany Pepin
 */


#include <gtest/gtest.h>
#include "VehiculePromenade.h"
#include "Vehicule.h"
using namespace saaq;
using namespace std;

/**
 * \brief Test du construc VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces);
 * 		Cas valide: creation d'un objet VehiculePromenade et verification de l'assignation de tout ses attributs
 * 		Cas invalide:
 * 			nombre de place > 0
 */
TEST(VehiculePromenade, ConstructeurAvecParametre)
{
	VehiculePromenade VehiculePromenadeTest("3VWFE21C04M000001", "A00 ABC", 4);
	ASSERT_EQ("3VWFE21C04M000001", VehiculePromenadeTest.reqNiv());
	ASSERT_EQ("A00 ABC", VehiculePromenadeTest.reqImmatriculation());
	ASSERT_EQ(4, VehiculePromenadeTest.reqNbPlaces());
}
// cas invalide
TEST(VehiculePromenade, ConstructeurNbPlacesInvalide)
{
	ASSERT_THROW(VehiculePromenade VehiculePromenadeTest("3VWFE21C04M000001", "A00 ABC", -1);, PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la classe de test
 */
class UnVehiculePromenade: public ::testing::Test
{
public:
	UnVehiculePromenade():
		unVehiculePromenade("3VWFE21C04M000001","A00 ABC", 4)
	{
	}
	;
	VehiculePromenade unVehiculePromenade;
};

/**
 * \brief Test de la methode reqNbPlaces()
 * 		cas valide : verifier le retour du poids du vehicule de promenade
 * 		cas invalide: non identifier
 */
TEST_F(UnVehiculePromenade, reqNbPlaces)
{
	ASSERT_EQ(4, unVehiculePromenade.reqNbPlaces());
}

/**
 * \brief Test de la methode std::string VehiculePromenade::reqVehiculeFormate()
 * 		Cas valide: verifier le retour des information de l'objet VehiculePromenade formater
 * 		Cas invalide: non identifier
 */

TEST_F(UnVehiculePromenade, reqVehiculeFormate)
{
	util::Date uneDate;
	std::ostringstream os;
	os << "Numero de serie : " << unVehiculePromenade.reqNiv() << std::endl
	<< "Numero d'immatriculation : " << unVehiculePromenade.reqImmatriculation() << std::endl
	<< "Date d'enregistrement : " << uneDate.reqDateFormatee()<< std::endl
	<< "Nombre de places: " << unVehiculePromenade.reqNbPlaces() << std::endl
	<< "tarif: " << unVehiculePromenade.tarificationAnnuelle()<<"$" <<  endl;
	ASSERT_EQ(os.str(), unVehiculePromenade.reqVehiculeFormate());

}
