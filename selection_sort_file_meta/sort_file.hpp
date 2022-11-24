// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

template <class T, class CONT>
void read_file_to_cont(std::ifstream& f, CONT& c) {
    if constexpr(std::is_same_v<T, char>) {
        char element;
        while ((element = f.get())) {
            if (element != '\n')
	    {
                c.insert(c.end(), element);
	    }
        }
    }
    else {
        T element;
        while (f >> element) {
            c.insert(c.end(), element);
        }
    }
}

template <class T, class CONT>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
  auto c = CONT();
  read_file_to_cont<T, CONT>(fi, c);
  my_selection_sort(c.begin(), c.end());
  for (auto &element : c) {
      fo << element << std::endl;
  }
}

template <class T>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  char container_type;
  fi >> container_type;
  fo << container_type << std::endl;
  switch(container_type)
  {
      case 'd':
          read_and_sort<T, std::deque<T>>(fi, fo);
          break;
      case 'v':
          read_and_sort<T, std::vector<T>>(fi, fo);
          break;
      case 'l':
          read_and_sort<T, std::list<T>>(fi, fo);
          break;
  }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    char value_type;
    fi >> value_type;
    fo << value_type << std::endl;
    switch(value_type)
  {
      case 's':
          read_and_sort_decide_container<std::string>(fi, fo);
          break;
      case 'u':
          read_and_sort_decide_container<unsigned>(fi, fo);
          break;
      case 'c':
          read_and_sort_decide_container<char>(fi, fo);
          break;
      case 'd':
          read_and_sort_decide_container<double>(fi, fo);
          break;
      case 'i':
          read_and_sort_decide_container<int>(fi, fo);
          break;
  }
}
// Step 1: decide value type of elements
// Step 2: decide type of container to use
// Step 3: read input file to decided container
// Step 4: Sort container

