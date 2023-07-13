#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int contaNos();
    int contaImpar();
    int contaFolhaImpar();
    int altura();
    void imprimeNivel(int k);
    int contaNosFolhas();
    float mediaNivel(int k);
    int min();
    int max();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    bool ehEmOrdem();
    int* retornaEmOrdemVet();
    void imprimeEmOrdem();
    void removeNo();

  private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    NoArv* auxInsere(NoArv *p, int x);
    int auxContaNos(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxMediaNivel(NoArv *p, int atual, int k, int *numValores);
    void auxMin(NoArv *p, int *menor);
    void auxMax(NoArv *p, int *maior);
    void auxInverte(NoArv *p);
    int auxNoEsq(NoArv *p);
    int auxNoDir(NoArv *p);
    void auxEmOrdem(NoArv *p, int* emOrdem, int* i );
};

#endif // ARVBIN_H_INCLUDED
