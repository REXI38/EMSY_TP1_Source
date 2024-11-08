/*************************************************/
/**	titre : TP1 EMSY Sparky linux		**/
/**	auteur : Louis cardinaux		**/
/**	coauteur : frédérique goyet		**/
/**	date : 08.11.2024			**/
/**						**/
/*************************************************/

/***************************/
/**  Guide des commandes  **/
/***************************/

/*********************************************************************************/

/**   Installer sparkylinux   **/

```
cd /					//aller a la racine
sudo sparkylinux-installer		//lancé l'installeur
````

/*********************************************************************************/

/**   Changer la langue du clavier   **/
```
sudo pkg-reconfigure keyboard-configuration	//lance le sousprogramme de configuration du clavier
```
/*********************************************************************************/

/**   Pourcentage de la swap   **/
```
cat /proc/sys/vm/swappiness			//retourne la valeur en pourcentage de la swap
sudo sysctl vm.swappiness=[valeur 0-100]	//change la valeur de la swap temporairement (jusqu'au prochain démarage)
```
//ex : cat /proc/sys/vm/swappiness		//retourne le pourcentage de la swap (par défaut 60%)
//ex : sudo sysctl vm.swappiness=50		//change la valeur de la swap temporairement a 50%

/*********************************************************************************/
/**   Apartenance des utilisateur   **/
```
id [nom d'utilisateur]		//affiche la liste d'apartenance de l'utilisateur
```
//ex : id lf			//affiche la liste d'apartenance de l'utilisateur "lf"

/*********************************************************************************/

/**   Se déplacer dans les répertoirs   **/
```
cd /[nom du répertoir]
```
//ex : cd /		//se déplacer à la racine
//ex : cd /home		//se déplacer dans le répertoire home

/*********************************************************************************/

/**   Créer un répertoir   **/
```
mkdir /[répertoir existant]/[répertoir créé]
```
//ex : mkdir /home/EMSY_TP1_LCX_FGT

/*********************************************************************************/

/**   Changer les droits   **/
```
chmod u+[droits] /[répertoire]	//change les droits utilisateur
ls -ld /[répertoire]		//liste les droite du répertoire
```
//ex : chmod u+rwx /home	//donne les droits (Read, Write, eXecute) a l'utilisateur dans le répertoire /home
//ex : ls -ld /home		//affiche les droits relatif au répertoire /home pour l'utilisateur

/*********************************************************************************/

/**   installation   **/
```
apt-get install [nom du programme]
```
//ex : apt-get install nano
//ex : apt-get install git

/*********************************************************************************/

/**   Test application installée   **/
```
[nom du programme] --version	//retourne la version de l'application si elle est installée
```
//ex : nano --version
//ex : git --version
//ex : gcc --version

/*********************************************************************************/

/**   commande nano   **/
```
nano 
nano [nom de fichier]
```
//ex : nano 		//nouveaux fichier sans nom
//ex : nano Readme.md	//ouvre le fichier Readme.md

ctrl+g 			//Help
ctrl+o 			//write out
ctrl+w 			//where is
ctrl+k 			//cut
ctrl+t 			//execute
ctrl+c 			//locate
ctrl+x 			//quit
ctrl+r 			//read file
ctrl+\ 			//replace
ctrl+u 			//paste
ctrl+j 			//justify
ctrl+_ 			//go to line

/**   créer un fichier   **/
```
nano 			//nouveaux fichier sans nom
```
(éditer le fichier)

ctrl+x 			//quitté
Save modifid buffer	//voulez vou sauvgarder les modifications cliquer "Y" pour oui
File name to write	//entrer le nom du fichier puis cliquer sur "entrer"

(fichier créé et enregistré sous le nom donné)

/**   éditer un fichier   **/
```
nano Readme.md		//ouvre le fichier Readme.md
```
(éditer le fichier)

ctrl+x 			//quitté
Save modifid buffer	//voulez vou sauvgarder les modification cliquer "Y" pour oui

(fichier modifié et enregistré)

/*********************************************************************************/

/**   Git commande   **/
```
git clone <adresse serveur> 		//clone le dépot en local (répertoire actif) de celui a l'adresse du serveur
```
//ex : git clone https://github.com/REXI38/EMSY_TP1_Source.git	//Clone le dépot dans le répertoire
```
git add [nom du fichier]		//ajoute un ou plisieurs fichiers pour le commit
```
//ex : git add -A			//ajoute tout les fichier (-A = --all) pour le commit
```
git commit -m "votre commentaire" 	//crée un nouveau commit (-m) ajoute un message
```
//ex : git commit -m "update Source"	//crée le nouveau commit avc les message "update source"
```
git push 				//envoie les fichier prêt pour dans le commit
```
//ex : git push 			//envoie les fichiers sur le sereur

/*********************************************************************************/



/*******************************/
/**  Guide de l'installation  **/
/*******************************/

/*********************************************************************************/

/**   Préparation de la VM   **/

Create a New Virtual Machine	//créer une nouvelle VM
Installer disc image file (iso)	//sélectionner et chercher le fichier iso live CD sparkylinux puis "Next"
debian 11.x			//sélectionner OS Linux, Version debian 11.x puis 
Virtual machine name		//nommer la VM (ex : SparkyLinux-XXX-XXX) puis "Next"
Lacation			//choisir l'emplacement de sauvegarde (ex : C:\Users\Virtual Machines\SparkyLinux-XXX-XXX)
20Gb				//choisir la taille du disque 20Gb,
singel file		 	//choisir "fichier unique" pour la sauvegarde  "Next"
				//résumer des paramètre entré sélectionner "Finish"

(Machien virtuel prête)

/*********************************************************************************/

/**   Instalation sprakylinux   **/

cd /				//aller a la racine
sudo sparkylinux-installer	//lancer l'installateur
yes				//Choisir "Yes" pour continuer l'installation
no				//Voulez vous changer le clavier par défaut (US)
ok				//cliquer "OK" pour continuer

sda				//selectionner le disque a partitionner
gpt  				//sélectionner le nom du type (guid partition table)
new				//nouvelle partition default linux filesystem
10G				//taille de la partition 10Gb
type : default linux filesystem	//Sélectionner linux filesystem
write , yes , quit		//écrire !sauvegarde
new				//nouvelle partition 
5G				//taille de la partition 5Gb
type : Linux swap		//Sélectionner Linux swap
write , yes , quit		//écrire !sauvegarde
				//laisser le reste en "free space"

select sd2 			//Sélectionner la partition pour "swap" puis "OK"
select sd1 			//Sélectionner la partition pour "root" puis "OK"

ext4	Ext4 file système	//sélectionner le type des fichier système puis "OK"

(le plus récent, avant btrfs plus stable)

password enter : "qwerty" = qwertz	//entrer un mots de passe puis "OK"
name : lcx-fgt (admin)			//entrer le nom de l'administrateur
nick name lf (admin)			//apréviation du nom de l'administrateur
password enter : "qwerty" = qwertz	//confirmer le mots de passe

host name: sparky			//nom de la machine
sda master boot record of disk		//sélectionner ou instatller le GRUB (Grand Unified Bootloader)
5   5 sec with no change		//sélectionner le temps d'attente avant le lancement de linux

non				//le système est t'il a l'heure local
Europe/amsterdam		//selectionner le fuso horaire puis "OK"
				
desktop instal			//installation d'un bureau selectionner "No"
reeboot and try linux 		//redémarer et tester linux selectionner "Yes"

(fin de l'installation)

/*********************************************************************************/



/***************************************/
/**  GRUB (Grand Unified Bootloader)  **/
/***************************************/

/*********************************************************************************/

/**   Image du démmarage du GRUB   **/

	###################################################################################
	########################### GNU GRUB version 2.04-20 ##############################
	###################################################################################
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@*Sparky GNU/Linux @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@ Advanced options for Sparky GNU/Linux @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #
	###################################################################################
	####### Use the ↑ and ↓ keys to select which entry is highlighted.#################
	####### Press enter to boot the selected OS, `e' to edit the commands #############
	####### before booting or `c' for a command-line.##################################
	#### The highlighted entry will be executed automatically in 5s.###################
	###################################################################################

//les .png c'est surfait

/*********************************************************************************/


/********************************/
/**  Configuration du clavier  **/
/********************************/

/*********************************************************************************/

/**   Changer la langue du clavier   **/

sudo dpkg-reconfigure keyboard-configuration	//lance le sousprogramme de configuration du clavier
keyboard model					//sélectionner "Generic 101-key PC"
keyboard layout					//sélectioner "Other"
Contry of origin for the keybord		//sélectionner "German (Switzerland)"
keyboard layout					//sélectionner "German (Switzerland) - French (Switzerland)"
key to function as AltGr			//sélectionner "The default for the keyboard layout"
compose key					//sélectionner "Right alt (AltGr)"

(langue du clavier changé)

/*********************************************************************************/
