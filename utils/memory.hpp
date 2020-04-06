#include <cstdlib>
#include <new>

template <class T>
std::decay_t<T>* new_struct() {
	// malloc mem and in-place construct
	if (const auto mem = std::malloc(sizeof(std::decay_t<T>)))
		return new (mem) std::decay_t<T>{};
	else 
		return nullptr;
}

template <class T>
std::decay_t<T>* new_struct(size_t count) {
	// malloc mem and in-place construct
	if (const auto mem = std::malloc(sizeof(std::decay_t<T>) * count))
		return new (mem) std::decay_t<T>[count]{};
	else
		return nullptr;
}
