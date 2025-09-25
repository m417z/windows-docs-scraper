HRESULT Create(
  [in]          IOpcPartUri                 *partUri,
  [in]          LPCWSTR                     digestMethod,
  [in]          OPC_CANONICALIZATION_METHOD transformMethod,
  [out, retval] IOpcSignaturePartReference  **partReference
);