HRESULT TryGetFontTable(
  [in]  UINT32     openTypeTableTag,
  [out] const void **tableData,
  [out] UINT32     *tableSize,
  [out] void       **tableContext,
  [out] BOOL       *exists
);