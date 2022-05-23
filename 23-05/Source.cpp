#include <iostream>
#include <string.h>
using namespace std;

class String {
public:

	String()
		:data(nullptr),
		size(0),
		capacity(0)

	{
		/*data = nullptr;
		size = 0;
		capacity = 0;
		cout << this <<  "Base object created\n";*/
	}
	explicit String(int length) : String(){
		capacity = length;
		data = new char[length] {};
		//size = 0; // ��� �� �����, �.� ��������� ��� �� ���������
	}

	~String() {
		if (data)
		{
			delete[] data;
		}
		cout << this << "Base object destroyed\n";
	}

	String(const char* str) {
		size = ::strlen(str)+1;
		capacity = size;
		data = new char[size] {};
		::memcpy(data,str,size);
	}

	String(const String& other) {
		size = other.size;
		capacity = other.capacity;
		data = new char[other.size] {};
		::memcpy(data, other.data, size);
		cout << this << "Base object created by copy\n";
	}

	const String& operator = (const String& other) {
		if (capacity >= other.size)
		{
			for (int i = 0; i < size; i++){
				data[i] = '\0'; 
			}
		}
		else
		{
			if (data)
			{
				delete[] data;
			}
			data = new char[other.size + 1];
			capacity = other.size + 1;
		}
		size = other.size;
		::memcpy(data, other.data, size);
		//������� �����������
		return *this;
	}
	void setString(const char* str) {
		(*this) = String(str); 
	}
	friend String operator + (String a, String b) {
		String result(a.size + b.size);
		::memcpy(result.data, a.data, a.size);
		::memcpy(result.data + a.size, b.data, b.size);
		result.size = a.size + b.size;
		return result;
	}
	String(String&& other):String() {
		swap(data, other.data);
		size = other.size;
		other.size = 0;
		swap(capacity, other.capacity);
	}

private:
	char* data;
	int size;
	int capacity;

};
void F00(String obj){ 

};


int main() {

	String a;
	String b(5);
	String(); // ��������� ������
	auto point = new String(4); // ����� ������������� ������������ � ���������� // Base* point = ...
	F00(static_cast<String>(8)); //F00(Base())
	double r = (1 / double(6));
	double e;
	e = r = 5.6;

	
	return 0;
}