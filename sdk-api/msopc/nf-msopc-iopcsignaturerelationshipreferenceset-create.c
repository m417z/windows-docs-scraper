HRESULT Create(
  [in]          IOpcUri                            *sourceUri,
  [in]          LPCWSTR                            digestMethod,
  [in]          OPC_RELATIONSHIPS_SIGNING_OPTION   relationshipSigningOption,
  [in]          IOpcRelationshipSelectorSet        *selectorSet,
  [in]          OPC_CANONICALIZATION_METHOD        transformMethod,
  [out, retval] IOpcSignatureRelationshipReference **relationshipReference
);