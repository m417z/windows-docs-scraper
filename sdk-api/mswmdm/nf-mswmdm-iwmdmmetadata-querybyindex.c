HRESULT QueryByIndex(
  [in]  UINT              iIndex,
  [out] WCHAR             **ppwszName,
  [out] WMDM_TAG_DATATYPE *pType,
  [out] BYTE              **ppValue,
  [out] UINT              *pcbLength
);