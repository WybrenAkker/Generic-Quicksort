//
// Created by Wybren on 3/1/2021.
// Note: 'Function' implementations are in the header file because it is impossible to define them elsewhere since they're templates.
//
#pragma once
#include <cmath>

namespace Extensions::CustomSorting
{
    class QuickSorter
    {
        public:
        ///<summary>
        ///Two possible methods of sorting an array. Influences the Partition method.
        ///</summary>
        // #dza: use scoped enums: `enum class SortingMethod{}`
        enum SortingMethod
        {
            Ascending, Descending
        };

        ///<summary>
        /// Generic Quicksort algorithm that can order any array by any value. (As long as said value has a < and > operator.)
        /// \tparam *array: Pointer to the array you want to sort.
        /// \tparam firstIndex: The starting index of the array you want to sort.
        /// \tparam lastIndex: The final index of the array you want to sort.
        /// \tparam variable: A generic lambda function that should take one value of type T and return the value you want to sort by.
        /// \tparam method: The sorting method you want to use. This algorithm is currently capable of sorting from lowest to highest (ascending) and highest to lowest (descending)
        ///</summary>
        // #dza: you mix explicit template parameters (T) with implicit ones (auto variable). that's confusing
        template<typename T>
        // #dza: Generally speaking, you should take `T array` the type T would be then deduced to a pointer for you case
        // but Sort would become more generic and will be able to work with pointer-like objects
        static inline void Sort(T *array, size_t firstIndex, size_t lastIndex, auto variable, SortingMethod method)
        {
            if (firstIndex<lastIndex)
            {
                size_t pivot = Partition<T>(array, firstIndex, lastIndex, variable, method);
                Sort(array, firstIndex, pivot, variable, method
                );
                Sort(array, pivot
                            + 1, lastIndex, variable, method);
            }
        }

        private:

        ///<summary>
        /// Gets input from the user in the form of a string and limits its size to maxCharacters.
        /// \tparam maxCharacters: The maximum amount of characters allowed in the string.
        /// \return Returns data entered by user.
        ///</summary>
        template<typename T> [[nodiscard]]
        static size_t Partition(T *array, size_t firstIndex, size_t lastIndex, auto variable, SortingMethod method)
        {
            //Calculate a pivot and define two indices.
            T pivot = array[static_cast<size_t>(floor(lastIndex + firstIndex) / 2)];
            size_t i = firstIndex - 1;
            size_t j = lastIndex + 1;

            // #dza: while (true)
            // #dza: performance: first switch then while
            while (1)
            {
                switch (method)
                {
                    case Ascending: //Sort the array from low to high values.
                    {
                        do
                        {
                            i++;
                        } while (variable(array[i]) < variable(pivot));

                        do
                        {
                            j--;
                        } while (variable(array[j]) > variable(pivot));
                        break;
                    }
                    case Descending: //Sort the array from high to low values.
                    {
                        do
                        {
                            i++;
                        } while (variable(array[i]) > variable(pivot));

                        do
                        {
                            j--;
                        } while (variable(array[j]) < variable(pivot));
                        break;
                    }
                }

                if (i >= j) //Check if the two indices have met each other.
                {
                    return j; //Return final index.
                }

                std::swap(array[i], array[j]); //Swap the position of the two encountered inversions as they are currently in the wrong order.
            }
        }
    };


}





