HRESULT GetCodecProp(
  [in]      DWORD             dwFormat,
  [in]      LPCWSTR           pszName,
  [out]     WMT_PROP_DATATYPE *pType,
  [out]     BYTE              *pValue,
  [in, out] DWORD             *pdwSize
);