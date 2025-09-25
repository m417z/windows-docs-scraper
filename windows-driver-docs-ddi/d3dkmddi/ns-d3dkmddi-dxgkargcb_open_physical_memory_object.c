typedef struct _DXGKARGCB_OPEN_PHYSICAL_MEMORY_OBJECT {
  [in]  HANDLE hPhysicalMemoryObject;
  [in]  HANDLE hAdapter;
  [out] HANDLE hAdapterMemoryObject;
} DXGKARGCB_OPEN_PHYSICAL_MEMORY_OBJECT;