/**
 * \file VehiculePromenade.h
 * \brief Declaration de la classe VehiculePromenade qui herite de la classe Vehicule
 * \date 2019-11-09
 * \author: Dany Pepin
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_
#include "Vehicule.h"
namespace saaq{
/**
 *\class VehiculePromenade
 *\brief Cette classe permet de gerer les Vehicules de promenades et habitation motorisee
 *\brief Herite de la classe Vehicule
 */
class VehiculePromenade : public Vehicule
{
public:
	VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces);
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;
	int reqNbPlaces() const;
	double tarificationAnnuelle() const;
	void asgImmatriculation(const std::string& p_immatriculation);

private:
	void verifieInvariant() const;
	int m_nbPlaces;
	std::string m_immatriculation;
};
} /*namspace*/
#endif /* VEHICULEPROMENADE_H_ */
