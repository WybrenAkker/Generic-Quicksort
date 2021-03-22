# CPP quicksorter

Hi! I'm Wybren and I'm new to this whole CPP thing. I moved from C# to CPP a while ago and this is my attempt at making a generic Quicksorting algorithm.

However, you're probably better off just using std::sort.


Sorting is relatively easy:

```cpp=
static inline void Sort(T *array, size_t firstIndex, size_t lastIndex, auto variable, SortingMethod method)
```

The method takes a pointer to the array, its first and last index, a *lambda* expression and one of two options:

```cpp=
enum SortingMethod
{
    Ascending, Descending
};
```

An example lambda expression would be:
```cpp=
[](ClassName a) {return a.value;}
```

As you can see all the lambda expression `value` is used for is extracting the value you want to sort on from the datatype. If for example you want to sort on a builtin type like an int you'd do this:

```cpp=
[](int a) {return a;}
```

Thanks for checking out my code! 