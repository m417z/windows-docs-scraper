typedef struct _DXGKARGCB_UNMAP_PHYSICAL_MEMORY {
  HANDLE hPhysicalMemoryObject;
  void   *pBaseAddress;
  SIZE_T Size;
} DXGKARGCB_UNMAP_PHYSICAL_MEMORY;