#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>
#include <iostream>

/**
 * \brief Класс линейного односвязного списка значений типа int.
 */
class LinkedListInt
{
private:

	/**
	 * \brief Структура узла ЛОС значений типа int.
	 */
	struct Node
	{
		int value;
		Node* next;
		~Node();
	};

public:

	/**
	 * \brief Конструктор по умолчанию.
	 */
	LinkedListInt();

	/**
	 * \brief Конструктор с параметром.
	 * \param init Список инициализации
	 */
	LinkedListInt(std::initializer_list<int> init);

	/**
	 * \brief Конструктор копирование.
	 * \param rhs Копируемое значение
	 */
	 //LinkedListInt(const LinkedListInt& rhs);

	 /**
	  * \brief Конструктор перемещения.
	  * \param rhs Перемещаемое значение
	  */
	  //LinkedListInt(LinkedListInt&& rhs);

	  /**
	   * \brief Деструктор.
	   */
	~LinkedListInt();

	/**
	 * \brief Оператор присваивания копированием.
	 * \param rhs Присваиваемое значение
	 * \return Левосторонняя часть
	 */
	LinkedListInt& operator=(const LinkedListInt& rhs) = delete;

	/**
	 * \brief Оператор присваивания перемещением.
	 * \param rhs Перемещаемое значение
	 * \return Левосторонняя часть
	 */
	LinkedListInt& operator=(LinkedListInt&& rhs) = delete;

	/**
	 * \brief Получение размера списка.
	 * \return Кол-во элементов в списке
	 */
	std::size_t size() const;

	/**
	 * \brief Проверка списка на пустоту.
	 * \return true, если список пуст
	 */
	bool empty() const;

	/**
	 * \brief Очитка списка.
	 */
	void clear();

	/**
	 * \brief Получение значения первого элемента списка.
	 * \return Значение первого элемента
	 */
	int& front() const;

	/**
	 * \brief Получение значения последнего элемента списка.
	 * \return Значение последнего элемента
	 */
	int& back() const;
	/**
	 * \brief Вставить значение после указанного элемента списка.
	 * \param pos Позиция после которой произвести вставку
	 * \param value Значение для вставки
	 */
	void insert(int pos, int value);

	 /**
	  * \brief Вставить элемент в начало списка.
	  * \param value Значение
	  * \return Итератор, указывающий на вставленный элемент
	  */
	void push_front(const int value);

	/**
	 * \brief Вставить элемент в конец списка.
	 * \param value Значение
	 * \return Итератор, указывающий на вставленный элемент
	 */
	void push_back(const int value);

	/**
	 * \brief Удалить элемент из начала списка.
	 * \return Значение удалённого элемента
	 */
	int pop_front();

	/**
	 * \brief Удалить элемент с конца списка.
	 * \return Значение удалённого элемента
	 */
	int pop_back();

	/**
	 * \brief Удалить элемент после указанного.
	 * \param pos Итератор, указывающий на элемент, после которого нужно удалить элемент.
	 * \return Значение удалённого элемента
	 */
	int erase_after(const int pos);

	/**
	 * \brief Удалить элемент.
	 * \param pos Итератор, указывающий на удаляемый элемент
	 * \return Значение удалённого элемента
	 */
	int erase(const int pos);

	/**
	 * \brief Преобразовать список в строку элементов с указанным разделителем.
	 * \value splitter Разделитель (по умолчанию запятая с пробелом)
	 * \return Строка значений
	 */
	std::string to_string(const std::string& splitter = ", ") const;

	  /**
	   * \brief Дружественная функция класса для добавления значения из потока.
	   * \value stream Поток
	   * \value list Список
	   */
	friend std::istream& operator>>(std::istream& stream, LinkedListInt& list);

private:

	/**
	 * \brief Кол-во элементов в списке.
	 */
	std::size_t count;

	/**
	 * \brief Указатели на первый и последний элемент списка (nullptr, если список пуст).
	 */
	Node* head;
	Node* tail;
};
