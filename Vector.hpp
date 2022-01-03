#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include <string>
#include <fstream>

template<class T> class Vector
{
private:
    T* Value_Array;
    T filereader;
    unsigned int Vector_Size = 0;//hur m�nga som �r upptagna
    unsigned int Vector_Max_Size = 10;// Max antal platser i vectorn

public:
    Vector(const Vector&) = delete;
    Vector(Vector&&) = delete;
    Vector& operator=(const Vector&) = delete;

    Vector(unsigned int startingCapacity = 10);
    ~Vector();

    void PushBack(const T& element);// l�gger till elementet p� f�rsta lediga plats om ingen plats finns ska en ny arrey skapas d�r de gammla v�rderna ligger kvar.
    void PopBack();//Ska ta bort sista upptagna platsen i arrayen

    T& operator[](unsigned int index);

    unsigned int Size() const;//Retunerar hur m�nga platser i vectorn som �r upptagna
    unsigned int Capacity() const;//Retunerar hur m�nga ledig platser vectorn har
    void Clear();//Tar bort allt i vectorn
    void Sort();//Sorterar fr�n minsta till f�rsta
    bool ReadFromFile(const std::string& filename);//skriver fr�n filen till vektorn
    bool WriteToFile(const std::string& filename) const;//Skriver fr�n vektorn till filen 


};

template<typename T>
Vector<T>::Vector(unsigned int startingCapacity = 10)
{
    Value_Array = new T[startingCapacity];
}


template<typename T>
Vector<T>::~Vector()
{
    delete[] Value_Array;
}


template<typename T>
void Vector<T>::PushBack(const T& element)// l�gger till elementet p� f�rsta lediga plats om ingen plats finns ska en ny arrey skapas d�r de gammla v�rderna ligger kvar.
{
    if (Vector_Size == Vector_Max_Size)
    {
        Vector_Max_Size = Vector_Max_Size * 2;
        T* temp_array = new T[Vector_Max_Size];
        for (unsigned int i = 0; i < Vector_Size; i++)
        {
            temp_array[i] = Value_Array[i];
        }
        delete[]Value_Array;
        Value_Array = temp_array;
    }
    Value_Array[Vector_Size] = element;
    Vector_Size++;
}


template<typename T>
void Vector<T>::PopBack()//Ska ta bort sista upptagna platsen i arrayen
{
    T* temp_array = new T[Vector_Max_Size];
    for (unsigned int i = 0; i < (Vector_Size - 1); i++)
    {
        temp_array[i] = Value_Array[i];
    }
    delete[]Value_Array;
    Value_Array = temp_array;
    Vector_Size--;
}


template<typename T>
T& Vector<T>::operator[](unsigned int index)
{
    return Value_Array[index];
}


template<typename T>
unsigned int Vector<T>::Size() const//Retunerar hur m�nga platser i vectorn som �r upptagna
{
    return Vector_Size;
}


template<typename T>
unsigned int Vector<T>::Capacity() const//Retunerar hur m�nga ledig platser vectorn har
{
    unsigned int Empty_slots = Vector_Max_Size - Vector_Size;
    return Empty_slots;
}


template<typename T>
void Vector<T>::Clear()//Tar bort allt i vectorn
{
    Vector_Size = 0;

    T* Temp_array = new T[Vector_Max_Size];
    delete[] Value_Array;
    Value_Array = Temp_array;
}


template<typename T>
void Vector<T>::Sort()//Sorterar fr�n minsta till f�rsta
{
    T temp;
    for (unsigned int i = 0; i < Vector_Size - 1; i++)
    {
        for (unsigned j = i + 1; j < Vector_Size; j++)
        {
            if (Value_Array[j] < Value_Array[i])
            {
                temp = Value_Array[i];
                Value_Array[i] = Value_Array[j];
                Value_Array[j] = temp;
            }
        }
    }
}


template<typename T>
bool Vector<T>::ReadFromFile(const std::string& filename)//skriver fr�n filen till vektorn
{
    std::ifstream Read_File;

    Read_File.open(filename);
    if (!Read_File)
    {
        return false;
    }
    while (Read_File >> filereader)
    {
        PushBack(filereader);
    }

    Read_File.close();
    return true;
}


template<typename T>
bool Vector<T>::WriteToFile(const std::string& filename) const//Skriver fr�n vektorn till filen 
{
    std::ofstream Write_to_file;
    Write_to_file.open(filename);
    if (!Write_to_file)
    {
        return false;
    }
    for (unsigned int i = 0; i < Vector_Size; i++)
    {
        Write_to_file << Value_Array[i] << std::endl;
    }
    Write_to_file.close();
    return true;
}
#endif