/**
 * \file Vehicule.cpp
 * \brief Implantation de la classe Vehicule
 * \date 2019-10-17
 * \author: Dany Pepin
 */

#include "Vehicule.h"
#include "Date.h"
#include <sstream>
#include "validationFormat.h"
namespace saaq
{
/**
 * \brief Constructeur de la classe Vehicule avec parametres permettant de creer des objets Vehicule
 * \param[in] p_niv un string qui represente le numero d'identification du vehicule
 * \param[in] p_immatriculation un string qui represente le numero de la plaque du vehicule
 * \post m_immatriculation prend la valeur de p_immatriculation
 * \post m_niv prend la valeur de p_niv
 */
Vehicule::Vehicule(const std::string& p_niv,
		const std::string& p_immatriculation) :
		m_niv(p_niv), m_immatriculation(p_immatriculation)
{
	POSTCONDITION(m_immatriculation == p_immatriculation);
	POSTCONDITION(m_niv == p_niv);
	INVARIANTS();
}
/**
 * \brief retourne le numero d'identification du vehicule
 * \return un string qui represente le numero d'identification du vehicule
 */
const std::string& Vehicule::reqNiv() const
{
	return m_niv;
}

/**
 * \brief retourne le numero d'immatriculation du vehicule
 * \return un string qui represente le numero d'immatriculation du vehicule
 */
const std::string& Vehicule::reqImmatriculation() const
{
	return m_immatriculation;
}

/**
 *\brief Assignation d'un numero d'immatriculation a l'objet courant
 * \param[in] p_immatriculation un string qui represente le numero de la plaque d'immatriculation du vehicule
 * \pre p_immatriculation non vide
 * \post m_immatriculation prend la valeur de p_immatriculation
 */
void Vehicule::asgImmatriculation(const std::string& p_immatriculation)
{
	m_immatriculation = p_immatriculation;
	POSTCONDITION(m_immatriculation == p_immatriculation)
	INVARIANTS();
}

/**
 * \brief Affiche les information formatee du vehicule dans un string
 * \return les infos formatee du vehicule dans un string
 */
std::string Vehicule::reqVehiculeFormate() const
{
	std::ostringstream os;
	os << "Numero de serie : " << m_niv << std::endl
			<< "Numero d'immatriculation : " << m_immatriculation << std::endl
			<< "Date d'enregistrement : " << m_dateEnregistrement << std::endl;

	return os.str();

}
/**
 * \brief surcharge de l'operateur ==
 * \param[in] p_vehicule qui est un vehicule valide
 * \return un booleen indiquant si les deux vehicules sont egales ou pas
 */
bool Vehicule::operator==(const Vehicule& p_vehicule) const // comparaison sur tous les attribut
{
	if (m_niv == p_vehicule.m_niv
			&& m_immatriculation == p_vehicule.m_immatriculation)
	{
		return true;
	}
	else
	{
		return false;
	}

}


/**
 * \brief Verifie les invariants de la classe Vehicule
 */
void Vehicule::verifieInvariant() const
{
	INVARIANT(util::validerNiv(m_niv));
}

} //namespace saaq

