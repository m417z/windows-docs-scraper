typedef struct _DXVADDI_DECODEBUFFERDESC {
  [in] HANDLE            hBuffer;
  [in] D3DDDIFORMAT      CompressedBufferType;
  [in] UINT              BufferIndex;
  [in] UINT              DataOffset;
  [in] UINT              DataSize;
  [in] UINT              FirstMBaddress;
  [in] UINT              NumMBsInBuffer;
  [in] UINT              Width;
  [in] UINT              Height;
  [in] UINT              Stride;
  [in] UINT              ReservedBits;
  [in] DXVADDI_PVP_HW_IV *pCipherCounter;
} DXVADDI_DECODEBUFFERDESC;