typedef struct D3D11DDIARG_TESSELLATION_IO_SIGNATURES {
  [in] D3D10DDIARG_SIGNATURE_ENTRY *pInputSignature;
  [in] UINT                        NumInputSignatureEntries;
  [in] D3D10DDIARG_SIGNATURE_ENTRY *pOutputSignature;
  [in] UINT                        NumOutputSignatureEntries;
  [in] D3D10DDIARG_SIGNATURE_ENTRY *pPatchConstantSignature;
  [in] UINT                        NumPatchConstantSignatureEntries;
} D3D11DDIARG_TESSELLATION_IO_SIGNATURES;