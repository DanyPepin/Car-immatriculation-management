/**
 * \file Camion.h
 * \brief Declaration de la classe Camion qui herite de la classe Vehicule
 * \date 2019-11-09
 * \author: Dany Pepin
 */
#ifndef CAMION_H_
#define CAMION_H_
#include "Vehicule.h"

namespace saaq
{
/**
 *\class Camion
 *\brief Cette classe permet de gerer les Camions
 *\brief Herite de la classe Vehicule
 */
class Camion : public Vehicule
{
public:
	Camion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux);
	int reqPoids() const;
	int reqNbEssieux() const;

	double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;

	void asgImmatriculation(const std::string& p_immatriculation);

private:
	void verifieInvariant() const;
	int m_poids;
	int m_nbEssieux;
	std::string m_immatriculation;

};
} /* namespace */
#endif /* CAMION_H_ */
