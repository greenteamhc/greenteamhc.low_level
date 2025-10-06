typedef struct {
    int* data;   // Pointer to the underlying array
    int size;    // Current number of elements
    int capacity; // Maximum capacity of the array
} dynamicArray;

// Function prototypes
dynamicArray* createdynamicArray(int initialCapacity);
void destroydynamicArray(dynamicArray* arr);
void addElement(dynamicArray* arr, int value);
void getElement(dynamicArray* arr, int index);
int getdynamicArraySize(dynamicArray* arr);
void printdynamicArray(dynamicArray* arr);
