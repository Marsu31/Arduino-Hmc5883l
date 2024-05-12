#include "Hmc5883l.h"

Hmc5883l::Hmc5883l ( )
{
}


// TODO : -4096  ( 1110111111111111 ??? à mettre en #define) dans un registre x,y,z => overflow => erreur
// toujours lire les 6 registres (même si erreur) sinon il ne peut y avoir d'autre mesure
// le status register est utile en debug pour connaître l'état de la puce

void Hmc5883l::begin ( )
{
}


