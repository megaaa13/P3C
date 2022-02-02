#!/bin/bash
# affiche_param_2.sh

# Affichage du nom du script
echo "Le nom de mon script est : $0"
# Affichage du nombre de paramètres
echo "Vous avez passé $# paramètres"
# Liste des paramètres (un seul argument)
for param in "$*"
do
 echo "Voici la liste des paramètres (un seul argument) : $param"
done
# Liste des paramètres (un paramètre par argument)
echo "Voici la liste des paramètres (un paramètre par argument) :"
for param in "$@"
do
 echo -e " Paramètre : $param"
done
# Affichage du processus
echo "Le PID du shell qui exécute le script est : $$"
# Exécution d'une commande qui s'exécute en arrière-plan
sleep 100 &
# Affichage du processus lancé en arrière-plan
echo "Le PID de la dernière commande exécutée en arrière-plan est : $!"
# Affichage du code retour de la dernière commande "echo"
echo "Le code retour de la commande précédente est : $?"
# Génération d'une erreur
echo "Génération d'une erreur..."
# Affichage de la mauvaise commande
echo "ls /etc/password 2>/dev/null"
ls /etc/password 2>/dev/null
# Affichage du code retour de la dernière commande
echo "Le code retour de la commande précédente est : $?"
exit