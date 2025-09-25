typedef struct _D3DKMT_CREATEDCFROMMEMORY {
  [in]  VOID         *pMemory;
  [in]  D3DDDIFORMAT Format;
  [in]  UINT         Width;
  [in]  UINT         Height;
  [in]  UINT         Pitch;
  [in]  HDC          hDeviceDc;
  [in]  PALETTEENTRY *pColorTable;
  [out] HDC          hDc;
  [out] HANDLE       hBitmap;
} D3DKMT_CREATEDCFROMMEMORY;