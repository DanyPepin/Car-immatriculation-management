/**
 * \file validationFormat.h
 * \brief Declaration des methodes validerImmatriculation et validerNiv
 * \date 2019-10-17
 * \author: Dany Pepin
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>
namespace util
{

//bool validerImmatriculation (const std::string& p_immatriculation);

bool validerNiv (const std::string& p_niv);

bool validationImmatriculationPromenade (const std::string& p_immatriculation);

bool validationImmatriculationCamion (const std::string& p_immatriculation);
};
#endif /* VALIDATIONFORMAT_H_ */

