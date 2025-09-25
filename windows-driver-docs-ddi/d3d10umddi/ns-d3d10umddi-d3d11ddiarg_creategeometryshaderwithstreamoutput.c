typedef struct D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT {
  [in] const UINT                                        *pShaderCode;
  [in] const D3D11DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY *pOutputStreamDecl;
  [in] UINT                                              NumEntries;
  [in] const UINT                                        *BufferStridesInBytes;
  [in] UINT                                              NumStrides;
  [in] UINT                                              RasterizedStream;
} D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT;