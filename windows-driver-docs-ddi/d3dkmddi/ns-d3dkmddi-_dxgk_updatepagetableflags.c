typedef struct _DXGK_UPDATEPAGETABLEFLAGS {
  UINT Repeat : 1;
  UINT InitialUpdate : 1;
  UINT NotifyEviction : 1;
  UINT Use64KBPages : 1;
  UINT NativeFence : 1;
#if ...
  UINT Reserved : 27;
#else
  UINT Reserved : 28;
#endif
} DXGK_UPDATEPAGETABLEFLAGS;