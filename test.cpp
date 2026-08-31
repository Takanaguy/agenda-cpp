#include <iostream>
#include <vector>
#include <fstream>

struct Date{
    unsigned int jour,mois,année;
};
void afficher_Date(const Date &d){
    std::cout<<"vous avez choisis comme date le :"<<d.jour<<"/"<<d.mois<<"/"<<d.année<<std::endl;
}
bool estvalide(unsigned int mois){
    if (mois<=12 && mois >=1){
        return true;
    }
    else{
        return false;
    }
}

void dessin_triangle(int hauteur){
    for (int i = 0; i<hauteur;i++){
        for(int j= 0; j <= i; j++){
            std::cout<<"* ";
        }
        std::cout<<std::endl;
        
            
    }
}

void dessin_rectangle(int longueur, int largeur){
    for (int i=0; i<longueur;i++){
        for(int j=0;j<largeur;j++){
            std::cout<<"* ";
        }
        std::cout<<std::endl;

    }
}
void triangle_a_l_envers_improve(int hauteur){
    for (int i = 0; i < hauteur; i++){
        for (int espace = 0; espace < i; espace++){
            std::cout << " ";
        }
        for (int etoile = 0; etoile < (hauteur - i); etoile++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void triangle_miroir_gauche_droite(int hauteur){
    for (int i = 0; i < hauteur; i++){
        for (int espace = 0; espace < (hauteur - 1 - i); espace++){
            std::cout << " ";
        }
        for (int etoile = 0; etoile <= i; etoile++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void triangle_envers_haut_bas(int hauteur){
    for (int i = 0; i < hauteur; i++){
        for (int etoile = 0; etoile < (hauteur - i); etoile++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void triangle_envers_haut_bas_gauche_droite(int hauteur){
    for (int i = 0; i < hauteur; i++){
        for (int espace = 0; espace < i; espace++){
            std::cout << " ";
        }
        for (int etoile = 0; etoile < (hauteur - i); etoile++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void dessin_carré (int cote){
    for(int i=0;i<cote;i++){
        for(int j=0;j<cote;j++){
            std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
}

void sansReference(int x) {
    x = x + 100;
    std::cout << "Dans la fonction (sans &) : x = " << x << std::endl;
}

void avecReference(int &x) {
    x = x + 100;
    std::cout << "Dans la fonction (avec &) : x = " << x << std::endl;
}



int main() {
    std::cout << "Salut, le monde!" << std::endl;
    /*unsigned int jour;
    std::cout <<"Veuillez entrer un numéro de jour (1-7) : ";
    std::cin >> jour;
    std::cout << "Vous avez entré le jour numéro : " << jour << std::endl;
    std::cout <<"Entre un numéro de mois (1-12) :";
    unsigned int mois;
    std::cin >> mois;
    if (estvalide(mois)){
        std::cout<<"le mois est valide";
    }
    else {
        std::cout <<"le mois n'est pas valide";
    }
    */
   //std::cout<<"donne moi la taille d'un coté pour faire un carré en *"<< std::endl;
   unsigned int cote,longueur,largueur,haut;
   /*std::cin>> cote;
   dessin_carré(cote);
   std::cout<<"donne moi une longueur et une largueur pour faire un rectangle pour en *"<< std::endl;
   std::cin>>longueur>>largueur;
   dessin_rectangle(longueur,largueur);*/
   /*std::cout<<"donne moi une hauteur pour faire un triangle pour en *"<< std::endl;
   std::cin>>haut;
   dessin_triangle(haut);
   std::cout << "Version miroir gauche-droite :" << std::endl;
   triangle_miroir_gauche_droite(haut);
   std::cout << "Version envers haut-bas :" << std::endl;
   triangle_envers_haut_bas(haut);
   std::cout << "Version envers haut-bas ET gauche-droite :" << std::endl;
   triangle_envers_haut_bas_gauche_droite(haut);*/
   /*Date d;
   std::cout<<"donner moi un jour un mois et une année"<<std::endl;
   std::cin>>d.jour>>d.mois>>d.année;
   afficher_Date(d);

    int a = 5;
    sansReference(a);
    std::cout << "Apres sansReference, a vaut toujours : " << a << std::endl;

    int b = 5;
    avecReference(b);
    std::cout << "Apres avecReference, b vaut maintenant : " << b << std::endl;
    */

    std::vector <int> test;
    std::cout<<"vas y donne moi 5 notes à stocker dans un vector"<<std::endl;
    for (int i=0;i<5;i++){
        int note;
        std::cout<<"vas y go"<<std::endl;
        std::cin>>note;
        test.push_back(note);
    }

    std::vector <int> notes;
    for (int i=0;i<5;i++){
        int note;
        std::cout<<"vas y go"<<std::endl;
        std::cin>>note;
        notes.push_back(note);
    }
    for (int n : notes) {
    std::cout << n << std::endl;
}
    for (int n : test) {
        std::cout << n << std::endl;

}

    std::cout << "Taille de test : " << test.size() << std::endl;
    std::cout << "Taille de notes : " << notes.size() << std::endl;
    
    std::ofstream fichier;
    fichier.open("test.txt",std::ios::out);
    if (!fichier.is_open()) {
    std::cout << "Erreur, le fichier n'a pas pu être ouvert." << std::endl;
}
    for (int n :notes){
        fichier<<n<<std::endl;
    }
    fichier.close();
    std::ifstream fichiers;


    fichiers.open("test.txt",std::ios::in);
    if (!fichiers.is_open()) {
    std::cout << "Erreur, le fichier n'a pas pu être ouvert." << std::endl;
}
    std::string ligne;
    while(std::getline(fichiers,ligne)){
        std::cout<<ligne<<std::endl;
    }
    fichiers.close();

   return 0;
}


