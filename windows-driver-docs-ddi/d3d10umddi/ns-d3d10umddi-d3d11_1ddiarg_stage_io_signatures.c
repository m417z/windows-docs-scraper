typedef struct D3D11_1DDIARG_STAGE_IO_SIGNATURES {
  union {
         D3D11_1DDIARG_SIGNATURE_ENTRY  *pInputSignatureDeprecated;
    [in] D3D11_1DDIARG_SIGNATURE_ENTRY2 *pInputSignature;
  };
  [in] UINT  NumInputSignatureEntries;
  union {
         D3D11_1DDIARG_SIGNATURE_ENTRY  *pOutputSignatureDeprecated;
    [in] D3D11_1DDIARG_SIGNATURE_ENTRY2 *pOutputSignature;
  };
  [in] UINT  NumOutputSignatureEntries;
} D3D11_1DDIARG_STAGE_IO_SIGNATURES;