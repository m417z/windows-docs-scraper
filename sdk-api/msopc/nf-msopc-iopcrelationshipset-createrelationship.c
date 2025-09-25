HRESULT CreateRelationship(
  [in]          LPCWSTR             relationshipIdentifier,
  [in]          LPCWSTR             relationshipType,
  [in]          IUri                *targetUri,
  [in]          OPC_URI_TARGET_MODE targetMode,
  [out, retval] IOpcRelationship    **relationship
);