typedef struct _DXGKARGCB_MAP_PHYSICAL_MEMORY {
  [in]     HANDLE           hPhysicalMemoryObject;
  [in]     DXGK_ACCESS_MODE AccessMode;
  [in/out] SIZE_T           Offset;
  [in]     SIZE_T           Size;
  [out]    void             *pMappedAddress;
} DXGKARGCB_MAP_PHYSICAL_MEMORY;