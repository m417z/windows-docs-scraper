typedef struct _D3DDDIARG_DECODEEXECUTE {
  [in] HANDLE                   hDecode;
  [in] UINT                     NumCompBuffers;
  [in] DXVADDI_DECODEBUFFERDESC *pCompressedBuffers;
} D3DDDIARG_DECODEEXECUTE;