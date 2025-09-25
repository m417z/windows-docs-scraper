HRESULT GetIndexStatus(
  [in]      ASF_INDEX_IDENTIFIER *pIndexIdentifier,
  [out]     BOOL                 *pfIsIndexed,
  [out]     BYTE                 *pbIndexDescriptor,
  [in, out] DWORD                *pcbIndexDescriptor
);