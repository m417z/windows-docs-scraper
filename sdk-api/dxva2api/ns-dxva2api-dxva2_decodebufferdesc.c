typedef struct _DXVA2_DecodeBufferDesc {
  DWORD CompressedBufferType;
  UINT  BufferIndex;
  UINT  DataOffset;
  UINT  DataSize;
  UINT  FirstMBaddress;
  UINT  NumMBsInBuffer;
  UINT  Width;
  UINT  Height;
  UINT  Stride;
  UINT  ReservedBits;
  PVOID pvPVPState;
} DXVA2_DecodeBufferDesc;