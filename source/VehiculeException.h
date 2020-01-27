/**
 * \file VehiculeException.h
 * \brief Hierarchie d'exception
 * \date 2019-12-03
 * \author: Dany Pepin et Sara Amara
 */

#ifndef VEHICULEEXCEPTION_H_
#define VEHICULEEXCEPTION_H_
#include <stdexcept>


/**
 * \brief Cette classe permet de gerer les exceptions liees aux vehicules
 * param[in] p_raison la raison de l'exception
 */
class VehiculeException : public std::runtime_error
{
public:
	VehiculeException (const std::string& p_raison): std::runtime_error(p_raison)
	{
	}
};

/**
 * \brief Cette classe permet de gerer les exceptions des vehicules deja present
 * param[in] p_raison la raison de l'exception
 */
class VehiculeDejaPresentException : public VehiculeException
{
public:
	VehiculeDejaPresentException (const std::string& p_raison): VehiculeException(p_raison)
{
}
};
/**
 * \brief Cette classe permet de gerer les exceptions des vehicules absent
 * param[in] p_raison la raison de l'exception
 */
class VehiculeAbsentException: public VehiculeException
{
public:
	VehiculeAbsentException (const std::string& p_raison): VehiculeException(p_raison)
{
}
};

#endif /* VEHICULEEXCEPTION_H_ */
