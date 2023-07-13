#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "�rvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv *p)
{
    if (p == NULL) return 0;
    else {
        int ne = auxContaNos(p->getEsq());
        int nd = auxContaNos(p->getDir());

        return ne + nd + 1;
    }
}

int ArvBin::contaNosFolhas()
{
    return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv *p)
{
    if (p == NULL) return 0;
    else if (p->getEsq() == NULL && p->getDir() == NULL)
        return 1;
    else {
        int folhaDir = auxContaNosFolhas(p->getEsq());
        int folhaEsq = auxContaNosFolhas(p->getDir());
        return folhaDir + folhaEsq;
    }
}

int ArvBin::altura()
{
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p)
{
    if (p == NULL) return -1;
    else {
        int ladoEsq = auxAltura(p->getEsq());
        int ladoDir = auxAltura(p->getDir());

        if (ladoEsq > ladoDir) return ladoEsq + 1;
        else return ladoDir + 1;
    }

}

int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p)
{
    if (p == NULL) return 0;
    else {
        int ne = auxContaImpar(p->getEsq());
        int nd = auxContaImpar(p->getDir());

        if (p->getInfo() % 2 != 0) return ne + nd + 1;
        else return ne + nd;
    }
}

int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}

int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if (p == NULL) return 0;
    else if (p->getEsq() == NULL && p->getDir() == NULL)
        if (p->getInfo() % 2 != 0) return 1;
        else return 0;
    else {
        int folhaDir = auxContaFolhaImpar(p->getEsq());
        int folhaEsq = auxContaFolhaImpar(p->getDir());

        return folhaDir + folhaEsq;
    }
}

void ArvBin::imprimeNivel(int k)
{
    auxImpNivel(raiz, 0, k);
}

void ArvBin::auxImpNivel(NoArv *p, int atual, int k)
{
    if (p != NULL){
        if (atual < k){
            auxImpNivel(p->getEsq(), atual + 1, k);
            auxImpNivel(p->getDir(), atual + 1, k);
        }
        else {
            cout << p->getInfo() << " ";
        }
    }
}

float ArvBin::mediaNivel(int k)
{
    int numValores = 0;
    return auxMediaNivel(raiz, 0, k, &numValores) / numValores;
}

int ArvBin::auxMediaNivel(NoArv *p, int atual, int k, int *numValores)
{
    if (p == NULL) return 0;
    else {
        if (atual < k){
            int valEsq = auxMediaNivel(p->getEsq(), atual + 1, k, numValores);
            int valDir = auxMediaNivel(p->getDir(), atual + 1, k, numValores);

            return valEsq + valDir;
        }
        else {
            (*numValores)++;
            return (p->getInfo());
        }
    }
}

int ArvBin::min()
{
    int menor = raiz->getInfo();
    auxMin(raiz, &menor);
    return menor;
}

void ArvBin::auxMin(NoArv *p, int *menor)
{
    if (p != NULL)
    {
        int menorEsq = p->getInfo();
        int menorDir = p->getInfo();
        int dir, esq;
        auxMin(p->getEsq(), &menorEsq);
        esq = menorEsq;

        auxMin(p->getDir(), &menorDir);
        dir = menorDir;

        if (esq > dir) *menor = dir;
        else {
            *menor = esq;
        }
    }
}

//wip
int ArvBin::max()
{
    int maior = raiz->getInfo();
    auxMax(raiz, &maior);
    return maior;
}

void ArvBin::auxMax(NoArv *p, int *maior)
{
   if (p != NULL)
    {
        int maiorEsq = p->getInfo();
        int maiorDir = p->getInfo();
        int dir, esq;
        auxMax(p->getEsq(), &maiorEsq);
        esq = maiorEsq;

        auxMax(p->getDir(), &maiorDir);
        dir = maiorDir;

        if (esq < dir) *maior = dir;
        else {
            *maior = esq;
        }
    }
}

void ArvBin::inverte()
{

    auxInverte(raiz);
}

void ArvBin::auxInverte(NoArv *p){
    if (p->getEsq() != NULL && p->getDir() != NULL)
    {

        auxInverte(p->getEsq());

        auxInverte(p->getDir());

        NoArv *aux = new NoArv();

       // aux->setInfo(p->getDir());

        aux = p->getDir();

        p->setDir(p->getEsq());

        p->setEsq(aux);

    }

    else if (p->getEsq() != NULL) auxInverte(p->getEsq());

    else if (p->getDir() != NULL) auxInverte(p->getDir());
}

int ArvBin::noMaisEsquerda(){
    if (raiz == NULL)cout << "Arvore vazia!";
    else return auxNoEsq(raiz);
}

int ArvBin::auxNoEsq(NoArv *p){
    int noEsq;
    if (p->getEsq()!= NULL){
        noEsq = auxNoEsq(p->getEsq());
        return noEsq;
    }
    else return p->getInfo();
}

int ArvBin::noMaisDireita(){
    return 0;
}

int ArvBin::auxNoDir(NoArv *p){
    int noDir;
    if (p->getDir()!= NULL){
        noDir = auxNoDir(p->getDir());
        return noDir;
    }
    else return p->getInfo();
}

int* ArvBin::retornaEmOrdemVet(){
    int* emOrdem = new int[contaNos()];
    int i = 0;

    auxEmOrdem(raiz, emOrdem, &i);

    return emOrdem;
}

void ArvBin::imprimeEmOrdem(){
    int* emOrdem = new int[contaNos()];
    int i = 0;

    auxEmOrdem(raiz, emOrdem, &i);
    for (int j = 0; j < i; j++){
        cout << emOrdem[j] << " ";
    }

    cout << endl;

    delete [] emOrdem;
}

bool ArvBin::ehEmOrdem(){
    int* emOrdem = new int[contaNos()];
    int i = 0;

    auxEmOrdem(raiz, emOrdem, &i);

    bool ehOrdem = true;

    for (int j = 0; j < i; j++){
        if (emOrdem[j] > emOrdem[j+1]){
                ehOrdem = !ehOrdem;
                cout << emOrdem[j] << " eh maior que " << emOrdem[j+1] << endl;
                break;
        }
    }

    if (ehOrdem)return true;
    else return false;

    delete [] emOrdem;
}

void ArvBin::auxEmOrdem(NoArv *p, int* emOrdem, int* i ){
    if (p!= NULL){
        auxEmOrdem(p->getEsq(), emOrdem, i);
        emOrdem[*i] = p->getInfo();
        (*i)++;
        auxEmOrdem(p->getDir(), emOrdem, i);
    }
}

/*
bool ArvBin::ehABB(){
    return auxEhABB(raiz);
}

bool ArvBin::auxEhABB(NoArv *p){
*/
