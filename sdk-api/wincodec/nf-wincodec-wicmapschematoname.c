HRESULT WICMapSchemaToName(
  [in]      REFGUID guidMetadataFormat,
  [in]      LPWSTR  pwzSchema,
  [in]      UINT    cchName,
  [in, out] WCHAR   *wzName,
  [out]     UINT    *pcchActual
);