typedef struct _DXVACompBufferInfo {
  DWORD     NumCompBuffers;
  DWORD     WidthToCreate;
  DWORD     HeightToCreate;
  DWORD     BytesToAllocate;
  DWORD     Usage;
  D3DPOOL   Pool;
  D3DFORMAT Format;
} DXVACompBufferInfo;