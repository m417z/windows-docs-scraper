typedef struct _DXGKARGCB_MAPFRAMEBUFFERPOINTER {
  [in]     UINT   PhysicalAdapterIndex;
  [in]     SIZE_T Size;
  [in/out] SIZE_T Offset;
  [out]    PVOID  pBaseAddress;
} DXGKARGCB_MAPFRAMEBUFFERPOINTER;