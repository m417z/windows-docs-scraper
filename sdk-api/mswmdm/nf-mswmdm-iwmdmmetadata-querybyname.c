HRESULT QueryByName(
  [in]  LPCWSTR           pwszTagName,
  [out] WMDM_TAG_DATATYPE *pType,
  [out] BYTE              **pValue,
  [out] UINT              *pcbLength
);