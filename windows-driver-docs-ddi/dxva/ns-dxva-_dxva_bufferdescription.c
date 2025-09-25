typedef struct _DXVA_BufferDescription {
  DWORD dwTypeIndex;
  DWORD dwBufferIndex;
  DWORD dwDataOffset;
  DWORD dwDataSize;
  DWORD dwFirstMBaddress;
  DWORD dwNumMBsInBuffer;
  DWORD dwWidth;
  DWORD dwHeight;
  DWORD dwStride;
  DWORD dwReservedBits;
} DXVA_BufferDescription, *LPDXVA_BufferDescription;