typedef struct IO_Range_s {
  DWORDLONG IOR_Align;
  DWORD     IOR_nPorts;
  DWORDLONG IOR_Min;
  DWORDLONG IOR_Max;
  DWORD     IOR_RangeFlags;
  DWORDLONG IOR_Alias;
} IO_RANGE, *PIO_RANGE;