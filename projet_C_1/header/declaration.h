#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef enum
{
    REEL, OPERATEUR, FONCTION, ERREUR, FIN, PAR_OUV, PAR_FERM, VARIABLE, VAL_NEG
} typelexem;

typedef enum
{
    PLUS, MOINS, FOIS, DIV, PUIS
} typeoperator;

typedef enum
{
    ABS, SIN, SQRT, LOG, COS, TAN, EXP
} typefonction;

typedef enum
{
    DOUBLE_POINTS, FONC, CARACTERE_INCONNU
} typeerreur;

typedef union
{
    float reel;
    typefonction fonction;
    typeoperator operateur;
    typeerreur erreur;
} typevaleur;

/* Param�tre de Retour de l'Analise Lexicale et
   d'Entr�e de l'Analyse Syntaxique */
typedef struct
{
    typelexem lexem;
    typevaleur valeur;
} typejeton;

typedef struct typeAnalyse
{
    typejeton jeton;
    struct typeAnalyse * suiv;
} ana;
typedef ana* objet;

/* Param�tre de Retour de l'Analyse Syntaxique et
   d'Entr�e de l'�valuateur */
typedef struct el
{
    typejeton jeton;
    struct el * fils_g;
    struct el * fils_d;
} feuille;
typedef feuille* arbre;

/* Param�tre de Retour de l'�valuateur et
   d'Entr�e de l'Affichage */
typedef struct tracage
{
    double abscisse;
    double ordonnee;
    struct tracage * suiv;
} list_tracage;
typedef list_tracage* couple;

#endif // DECLARATION_H_INCLUDED
