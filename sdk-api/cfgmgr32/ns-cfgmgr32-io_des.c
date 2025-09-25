typedef struct IO_Des_s {
  DWORD     IOD_Count;
  DWORD     IOD_Type;
  DWORDLONG IOD_Alloc_Base;
  DWORDLONG IOD_Alloc_End;
  DWORD     IOD_DesFlags;
} IO_DES, *PIO_DES;