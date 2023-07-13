#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    arv.insere(15);
    arv.insere(25);
    arv.insere(10);
    arv.preOrdem();
    cout << endl;
    cout << "Altura: " << arv.altura() << endl;
    cout << "Conta nos: " << arv.contaNos() << endl;
    cout << "Conta Folhas: " << arv.contaNosFolhas() << endl;
    cout << "Conta impar: " << arv.contaImpar() << endl;
    cout << "Conta folhas impar: " << arv.contaFolhaImpar() << endl;
    arv.imprimeNivel(2);
    cout << "media em nivel (2): " << arv.mediaNivel(2) << endl;

    cout << "menor valor: " << arv.min() << endl;
    cout << "maior valor: " << arv.max() << endl;

    arv.inverte();

    arv.preOrdem();

    cout << endl;

    arv.inverte();

    cout << "no mais esq: " << arv.noMaisEsquerda() << endl;

    cout << "arvore em ordem: " << endl;
    cout << "A arvore eh de busca?: ";
    if (arv.emOrdem())cout << "Sim.";
        else cout << "Nao.";
    cout << endl;

    return 0;
}
