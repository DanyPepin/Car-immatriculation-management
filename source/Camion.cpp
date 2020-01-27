/**
 * \file Camion.cpp
 * \brief Implantation de la classe Camion
 * \date 2019-10-17
 * \author: Dany Pepin
 */
#include "Camion.h"
#include <sstream>
using namespace std;
namespace saaq
{

/**
 * \brief Constructeur de la classe Camion avec parametres permettant de creer des objets Camion
 * \param[in] p_niv un string qui represente le numero d'identification du Camion
 * \param[in] p_immatriculation un string qui represente le numero de la plaque du Camion
 * \param[in] p_poids un int qui represente le poids du camion
 * \param[in] p_nbEssieux un int qui represente le nombre d'essieux du camion
 * \pre p_poids plus grand que 3000 kg
 * \pre p_nbEssieux plus grand ou egale a 2
 * \post m_poids prend la valeur de p_poids
 */
saaq::Camion::Camion(const std::string& p_niv,
		const std::string& p_immatriculation, int p_poids, int p_nbEssieux)
		:Vehicule(p_niv, p_immatriculation), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
{
	PRECONDITION(p_poids > 3000);
	PRECONDITION(p_nbEssieux >= 2);
	POSTCONDITION(m_poids == p_poids);
	POSTCONDITION(m_nbEssieux == p_nbEssieux);
	INVARIANTS();
}

/**
 * \brief Accesseur pour le poids du Camion
 * \return le poids du camion
 */
int saaq::Camion::reqPoids() const
{
	return m_poids;
}

/**
 * \brief Acceseur pour le nombre d'essieux
 * \return le nombre d'essieux du camion
 */
int saaq::Camion::reqNbEssieux() const
{
	return m_nbEssieux;
}

/**
 * \brief Methode qui calcul la tarification selon le poids et le nombre d'essieux
 * \return tarif un double representant la tarification
 */
double saaq::Camion::tarificationAnnuelle() const
{
	double tarif;
	if(m_nbEssieux == 2 && m_poids >= 3001 && m_poids <= 4000)
	{
		tarif = 570.28;
	}
	if(m_nbEssieux == 2 && m_poids >= 4001)
	{
		tarif = 905.28;
	}
	if(m_nbEssieux == 4)
	{
		tarif = 2206.19;
	}
	if(m_nbEssieux == 5)
	{
		tarif = 2821.76;
	}
	if(m_nbEssieux >= 6)
	{
		tarif = 3729.76;
	}

	return tarif;

}
/**
 *\brief Assignation d'un numero d'immatriculation a l'objet courant
 * \param[in] p_immatriculation un string qui represente le numero de la plaque d'immatriculation du vehicule
 * \pre p_immatriculation non vide
 * \post m_immatriculation prend la valeur de p_immatriculation
 */
void Camion::asgImmatriculation(const std::string& p_immatriculation) // a revoir a cause pas sur de asg 1 parametre
{
	m_immatriculation = p_immatriculation;
	POSTCONDITION(m_immatriculation == p_immatriculation)
	INVARIANTS();
}

/**
 * \brief Fait une copie sur le monceau de l'objet courant Camion
 * \return La copie de l'objet Camion
 */
Vehicule* saaq::Camion::clone() const
{
	return new Camion(*this);
}

/**
 * Affichage des informations formatee du camion dans un string
 * \return Les infos formatee du camion dans un string
 */
std::string saaq::Camion::reqVehiculeFormate() const
{
	ostringstream os;
	os << Vehicule::reqVehiculeFormate()
	<< "Nombre d'essieux: " << m_nbEssieux << std::endl
	<< "poids: " << m_poids << "kg" << std::endl
	<< "tarif: " << tarificationAnnuelle() <<"$" <<  std::endl;
	return os.str();
}

/**
 * \brief Verifie les invariants de la classe Camion
 */
void saaq::Camion::verifieInvariant() const
{
	INVARIANT(m_poids > 3000);
	INVARIANT(m_nbEssieux >= 2);
}

}//namspace saaq
