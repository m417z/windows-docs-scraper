DECLSPEC_ALLOCATOR LPVOID HeapReAlloc(
  [in] HANDLE                 hHeap,
  [in] DWORD                  dwFlags,
  [in] _Frees_ptr_opt_ LPVOID lpMem,
  [in] SIZE_T                 dwBytes
);