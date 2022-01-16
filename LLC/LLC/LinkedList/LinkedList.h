#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>
#include <iostream>

/**
 * \brief ����� ��������� ������������ ������ �������� ���� int.
 */
class LinkedListInt
{
private:

	/**
	 * \brief ��������� ���� ��� �������� ���� int.
	 */
	struct Node
	{
		int value;
		Node* next;
		~Node();
	};

public:

	/**
	 * \brief ����������� �� ���������.
	 */
	LinkedListInt();

	/**
	 * \brief ����������� � ����������.
	 * \param init ������ �������������
	 */
	LinkedListInt(std::initializer_list<int> init);

	/**
	 * \brief ����������� �����������.
	 * \param rhs ���������� ��������
	 */
	 //LinkedListInt(const LinkedListInt& rhs);

	 /**
	  * \brief ����������� �����������.
	  * \param rhs ������������ ��������
	  */
	  //LinkedListInt(LinkedListInt&& rhs);

	  /**
	   * \brief ����������.
	   */
	~LinkedListInt();

	/**
	 * \brief �������� ������������ ������������.
	 * \param rhs ������������� ��������
	 * \return ������������� �����
	 */
	LinkedListInt& operator=(const LinkedListInt& rhs) = delete;

	/**
	 * \brief �������� ������������ ������������.
	 * \param rhs ������������ ��������
	 * \return ������������� �����
	 */
	LinkedListInt& operator=(LinkedListInt&& rhs) = delete;

	/**
	 * \brief ��������� ������� ������.
	 * \return ���-�� ��������� � ������
	 */
	std::size_t size() const;

	/**
	 * \brief �������� ������ �� �������.
	 * \return true, ���� ������ ����
	 */
	bool empty() const;

	/**
	 * \brief ������ ������.
	 */
	void clear();

	/**
	 * \brief ��������� �������� ������� �������� ������.
	 * \return �������� ������� ��������
	 */
	int& front() const;

	/**
	 * \brief ��������� �������� ���������� �������� ������.
	 * \return �������� ���������� ��������
	 */
	int& back() const;
	/**
	 * \brief �������� �������� ����� ���������� �������� ������.
	 * \param pos ������� ����� ������� ���������� �������
	 * \param value �������� ��� �������
	 */
	void insert(int pos, int value);

	 /**
	  * \brief �������� ������� � ������ ������.
	  * \param value ��������
	  * \return ��������, ����������� �� ����������� �������
	  */
	void push_front(const int value);

	/**
	 * \brief �������� ������� � ����� ������.
	 * \param value ��������
	 * \return ��������, ����������� �� ����������� �������
	 */
	void push_back(const int value);

	/**
	 * \brief ������� ������� �� ������ ������.
	 * \return �������� ��������� ��������
	 */
	int pop_front();

	/**
	 * \brief ������� ������� � ����� ������.
	 * \return �������� ��������� ��������
	 */
	int pop_back();

	/**
	 * \brief ������� ������� ����� ����������.
	 * \param pos ��������, ����������� �� �������, ����� �������� ����� ������� �������.
	 * \return �������� ��������� ��������
	 */
	int erase_after(const int pos);

	/**
	 * \brief ������� �������.
	 * \param pos ��������, ����������� �� ��������� �������
	 * \return �������� ��������� ��������
	 */
	int erase(const int pos);

	/**
	 * \brief ������������� ������ � ������ ��������� � ��������� ������������.
	 * \value splitter ����������� (�� ��������� ������� � ��������)
	 * \return ������ ��������
	 */
	std::string to_string(const std::string& splitter = ", ") const;

	  /**
	   * \brief ������������� ������� ������ ��� ���������� �������� �� ������.
	   * \value stream �����
	   * \value list ������
	   */
	friend std::istream& operator>>(std::istream& stream, LinkedListInt& list);

private:

	/**
	 * \brief ���-�� ��������� � ������.
	 */
	std::size_t count;

	/**
	 * \brief ��������� �� ������ � ��������� ������� ������ (nullptr, ���� ������ ����).
	 */
	Node* head;
	Node* tail;
};
