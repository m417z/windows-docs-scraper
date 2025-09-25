typedef struct _NTMS_ALLOCATION_INFORMATION {
  DWORD           dwSize;
#if ...
  LPNTMS_ASYNC_IO lpReserved;
#else
  LPVOID          lpReserved;
#endif
  NTMS_GUID       AllocatedFrom;
} NTMS_ALLOCATION_INFORMATION, *LPNTMS_ALLOCATION_INFORMATION;