// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <typename T>
void my_selection_sort(T begin, T end) {
    T firstEl = begin;
    while (firstEl != end)
    {
        T min = firstEl;
        T sto = firstEl;
        while (sto != end)
        {
            if (*min > *sto)
                min = sto;
            sto++;

        }
        
        auto check = *firstEl;
        *firstEl = *min;
        *firstEl = check;
        firstEl++;
    }


}
