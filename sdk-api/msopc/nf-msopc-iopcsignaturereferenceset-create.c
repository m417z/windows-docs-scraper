HRESULT Create(
  [in]          IUri                        *referenceUri,
  [in]          LPCWSTR                     referenceId,
  [in]          LPCWSTR                     type,
  [in]          LPCWSTR                     digestMethod,
  [in]          OPC_CANONICALIZATION_METHOD transformMethod,
  [out, retval] IOpcSignatureReference      **reference
);