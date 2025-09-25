typedef struct _D3DDDIARG_SETSTREAMSOURCE {
  [in] UINT   Stream;
  [in] HANDLE hVertexBuffer;
  [in] UINT   Offset;
  [in] UINT   Stride;
} D3DDDIARG_SETSTREAMSOURCE;