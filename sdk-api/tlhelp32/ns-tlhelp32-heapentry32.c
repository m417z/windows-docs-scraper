typedef struct tagHEAPENTRY32 {
  SIZE_T    dwSize;
  HANDLE    hHandle;
  ULONG_PTR dwAddress;
  SIZE_T    dwBlockSize;
  DWORD     dwFlags;
  DWORD     dwLockCount;
  DWORD     dwResvd;
  DWORD     th32ProcessID;
  ULONG_PTR th32HeapID;
} HEAPENTRY32;