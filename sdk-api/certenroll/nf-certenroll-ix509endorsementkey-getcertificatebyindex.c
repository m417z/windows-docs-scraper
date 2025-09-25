HRESULT GetCertificateByIndex(
  [in]          VARIANT_BOOL ManufacturerOnly,
  [in]          LONG         dwIndex,
  [in]          EncodingType Encoding,
  [out, retval] BSTR         *pValue
);