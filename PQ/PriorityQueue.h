/** ************************************************************************
 *
 * Fisier header pentru functiile necesare pentru cozile cu prioritati.
 *
 ***************************************************************************/

#pragma once

#include <cstdint>
#include <queue>

template <class T>
class PriorityQueue {
    /*
     * TODO: Adaugati aici campurile necesare. Atentie, aceste campuri nu se
     * vor putea accesa direct din main, ci doar din metodele de mai jos.
     */
    uint32_t maxPV;
    std::queue<T>* coada = NULL;
public:
    /**
     * Constructorul va crea un PriorityQueue.
     *
     * @param maxPriorityValue prioritatatea cea mai mica din coada (valoarea maxima).
     */
    PriorityQueue(uint32_t maxPriorityValue) {
        // TODO: scrieti codul aici
        maxPV = maxPriorityValue;
        coada = new std::queue<T>[maxPriorityValue + 1];
    }

    /**
     * Functia va intoarce numarul de elemente din coada.
     * @return numarul de elemente din coada.
     */
    uint32_t size() {
        // TODO: scrieti codul aici
        uint32_t S = 0;
        for(int i = 0; i < maxPV + 1; i++)
        {
            S += coada[i].size();
        }
        return S;
    }

    /**
     * Functia va intoarce true daca coada este goala.
     * @return true dacă coada este goala, altfel false
     */
    bool empty() {
        // TODO: scrieti codul aici
        if(this->size() == 0) return true;
        return false;
    }

    /**
     * Functia va insera in coada elementul cu prioritatea specificata.
     * @param value elementul care trebuie adaugat in coada.
     * @param priority prioritatea cu care se adauga in coada elementul.
     */
    void push(T value, uint32_t priority) {
        // TODO: scrieti codul aici
        coada[priority].push(value);
    }

    /**
     * Functia va extrage si elimina din coada pacientul cu prioritatea maxima.
     * @return elementul cu prioritatea maxima
     */
    T pop() {
        // TODO: scrieti codul aici
        T val;
        for(int i = 0; i < maxPV + 1; i++)
        {
            if(!coada[i].empty())
            {
                val = coada[i].front();
                coada[i].pop();
                break;
            }
        }
        return val;
    }

    /**
     * Destructorul dezaloca memoria utilizata de coada, daca s-a alocat in
     * constructor. Altfel, lasat-l gol.
     */
    ~PriorityQueue() {
        // TODO: scrieti codul aici
        delete[] coada;
    }
};