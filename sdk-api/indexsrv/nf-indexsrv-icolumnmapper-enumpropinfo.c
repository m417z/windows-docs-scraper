HRESULT EnumPropInfo(
  [in]  ULONG        iEntry,
  [out] const WCHAR  **pwcsName,
  [out] DBID         **ppPropId,
  [out] DBTYPE       *pPropType,
  [out] unsigned int *puiWidth
);