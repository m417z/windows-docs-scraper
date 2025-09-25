typedef struct D3D10DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT {
  [in] const UINT                                        *pShaderCode;
  [in] const D3D10DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY *pOutputStreamDecl;
  [in] UINT                                              NumEntries;
  [in] UINT                                              StreamOutputStrideInBytes;
} D3D10DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT;