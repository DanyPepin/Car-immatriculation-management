/**
 * \file VehiculePromenade.cpp
 * \brief Implantation de la classe VehiculePromenade
 * \date 2019-11-09
 * \author: Dany Pepin
 */

#include "VehiculePromenade.h"
#include <sstream>

using namespace std;

namespace saaq
{
/**
 * \brief Constructeur de la classe VehiculePromenade avec parametres permettant de creer des objets VehiculePromenade
 * \param[in] p_niv un string qui represente le numero d'identification du VehiculePromenade
 * \param[in] p_immatriculation un string qui represente le numero de la plaque du VehiculePromenade
 * \param[in] p_nbPlaces qui represente le nombre de place du VehiculePromenade
 * \pre p_nbPlaces plus grand que 0
 * \post m_nbPlaces prend la valeur de p_nbPlaces
 */
saaq::VehiculePromenade::VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces)
		:Vehicule(p_niv, p_immatriculation), m_nbPlaces(p_nbPlaces)
{
	PRECONDITION(p_nbPlaces > 0);
	POSTCONDITION(m_nbPlaces == p_nbPlaces);
	INVARIANTS();
}
/**
 * \brief Accesseur sur le nombre de place du vehicule de promenade
 * \return le nombre de place du vehicule promenade
 */
int VehiculePromenade::reqNbPlaces() const
{
	return m_nbPlaces;
}
/**
 *\brief Retourne la tarification annuelle fixe d'un vehicule de promenade soit 224.04$
 * \return un double qui represente la tarification annuelle d'un vehicule de promenade
 */
double VehiculePromenade::tarificationAnnuelle() const
{
	double tarif = 224.04;
	return tarif;
}

/**
 * \brief retourne les informations formatee du vehicule de proemande dans un string
 * \return les infos formatee du vehicule dans un string
 */
std::string VehiculePromenade::reqVehiculeFormate() const
{
	ostringstream os;
	os << Vehicule::reqVehiculeFormate()
	<< "Nombre de places: " << m_nbPlaces << std::endl
	<< "tarif: " << tarificationAnnuelle()<<"$" <<  endl;
	return os.str();
}

/**
 *\brief Fait une copie allouée sur le monceau de l'objet VehiculePromenade courant
 * \return La copie de l'objet VehiculePromenade
 */
Vehicule* VehiculePromenade::clone() const
{
	return new VehiculePromenade(*this);
}

/**
 *\brief Assignation d'un numero d'immatriculation a l'objet courant
 * \param[in] p_immatriculation un string qui represente le numero de la plaque d'immatriculation du vehicule
 * \pre p_immatriculation non vide
 * \post m_immatriculation prend la valeur de p_immatriculation
 */
void VehiculePromenade::asgImmatriculation(const std::string& p_immatriculation)
{
	m_immatriculation = p_immatriculation;
	POSTCONDITION(m_immatriculation == p_immatriculation)
	INVARIANTS();
}

/**
 * \brief verifie les invariants de la classe VehiculePromenade
 */
void VehiculePromenade::verifieInvariant() const
{
	INVARIANT(m_nbPlaces > 0);
}
} /* namespace */
