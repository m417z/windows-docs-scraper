typedef struct _DD_GETHEAPALIGNMENTDATA {
  ULONG_PTR     dwInstance;
  DWORD         dwHeap;
  HRESULT       ddRVal;
  VOID          *GetHeapAlignment;
  HEAPALIGNMENT Alignment;
} DD_GETHEAPALIGNMENTDATA, *PDD_GETHEAPALIGNMENTDATA;