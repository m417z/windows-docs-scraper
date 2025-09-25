HRESULT GetFormatProp(
  [in]      DMO_MEDIA_TYPE    *pmt,
  [in]      LPCWSTR           pszName,
  [out]     WMT_PROP_DATATYPE *pType,
  [out]     BYTE              *pValue,
  [in, out] DWORD             *pdwSize
);