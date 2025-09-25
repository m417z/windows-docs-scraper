typedef struct _DXVADDI_PRIVATEBUFFER {
  [in] HANDLE hResource;
  [in] UINT   SubResourceIndex;
  [in] UINT   DataOffset;
  [in] UINT   DataSize;
} DXVADDI_PRIVATEBUFFER;