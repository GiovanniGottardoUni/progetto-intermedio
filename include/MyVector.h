#ifndef MYVECTOR_H_
#define MYVECTOR_H_
#include <iostream>

/**
 * @class MyVector
 * @brief Implementazione di un vettore dinamico generico.
 *
 * La classe MyVector fornisce un contenitore simile a std::vector,
 * con supporto per inserimento, rimozione e accesso agli elementi.
 *
 * @tparam T Tipo degli elementi contenuti nel vettore
 */
template <typename T>
class MyVector
{

public:
	/**
	 * @brief Costruttore di default.
	 *
	 * Inizializza un vettore di dimensione specificata (default 0)
	 * con capacità iniziale predefinita.
	 *
	 * @param s Dimensione iniziale del vettore (default 0)
	 */
	MyVector(size_t s = 0);

	/**
	 * @brief Costruttore con initializer_list.
	 *
	 * Permette di inizializzare il vettore con una lista di valori.
	 *
	 * @param lst Lista di valori iniziali
	 */
	MyVector(std::initializer_list<T> lst);

	/**
	 * @brief Costruttore di copia.
	 *
	 * Copia tutti gli elementi dal vettore passato.
	 *
	 * @param other Vettore da copiare
	 */
	MyVector(const MyVector &other);

	/**
	 * @brief Costruttore di spostamento (move constructor).
	 *
	 * Sposta i dati da un altro vettore, invalidando il vettore sorgente.
	 *
	 * @param other Vettore da spostare
	 */
	MyVector(MyVector &&other) noexcept;

	/**
	 * @brief Distruttore.
	 *
	 * Dealloca la memoria del vettore.
	 */
	~MyVector();

	/**
	 * @brief Restituisce la dimensione corrente del vettore.
	 *
	 * @return Numero di elementi presenti
	 */
	size_t getSize() const;

	/**
	 * @brief Accesso in lettura/scrittura a un elemento.
	 *
	 * @param index Indice dell'elemento
	 * @return Riferimento all'elemento corrispondente
	 */
	T &operator[](const size_t index);

	/**
	 * @brief Accesso in sola lettura a un elemento.
	 *
	 * @param index Indice dell'elemento
	 * @return Riferimento const all'elemento corrispondente
	 */
	T &operator[](const size_t index) const;

	/**
	 * @brief Operatore di assegnamento move.
	 *
	 * @param other Vettore da spostare
	 * @return Riferimento al vettore corrente
	 */
	MyVector &operator=(MyVector &&);

	/**
	 * @brief Aggiunge un elemento alla fine del vettore.
	 *
	 * Se la capacità è insufficiente, viene raddoppiata.
	 *
	 * @param value Valore da aggiungere
	 */
	void push_back(const T value);

	/**
	 * @brief Rimuove l'ultimo elemento del vettore.
	 *
	 * @throw std::out_of_range se il vettore è vuoto.
	 */
	void pop_back();

	/**
	 * @brief Accesso in sola lettura a un elemento con controllo dei limiti.
	 *
	 * @param index Indice dell'elemento
	 * @return Riferimento const all'elemento corrispondente
	 * @throw std::out_of_range se l'indice è fuori dai limiti.
	 */
	T at(const size_t index) const;

private:
	size_t size;	 // numero di elementi attuali
	size_t capacity; // capacità massima attuale
	T *data;		 // array dinamico di elementi

	static const size_t INITIAL_CAPACITY = 100; // capacità iniziale predefinita

	/**
	 * @brief Riserva nuova capacità per il vettore.
	 *
	 * @param new_capacity Nuova capacità da riservare
	 */
	void reserve(size_t new_capacity);
};

#include "MyVector.hpp"

#endif /* MYVECTOR_H_ */
