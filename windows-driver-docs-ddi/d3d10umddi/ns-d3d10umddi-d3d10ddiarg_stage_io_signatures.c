typedef struct D3D10DDIARG_STAGE_IO_SIGNATURES {
  [in] D3D10DDIARG_SIGNATURE_ENTRY *pInputSignature;
  [in] UINT                        NumInputSignatureEntries;
  [in] D3D10DDIARG_SIGNATURE_ENTRY *pOutputSignature;
  [in] UINT                        NumOutputSignatureEntries;
} D3D10DDIARG_STAGE_IO_SIGNATURES;