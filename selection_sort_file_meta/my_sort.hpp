// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <class T>
T container_min(T begin, T end) {
    T min = begin++;
    while (begin != end) {
        if (*begin < *min)
	{
            min = begin;
	}
        begin++;
    }

    return min;
}

template <class T>
void my_selection_sort(T begin, T end) {
    while (end != begin) {
        T sami = container_min(begin, end);

        auto tmp = *sami;
        *sami = *begin;
        *begin = tmp;

        begin++;
    }
}
