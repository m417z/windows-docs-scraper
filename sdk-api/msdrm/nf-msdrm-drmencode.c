DRMEXPORT HRESULT UDAPICALL DRMEncode(
  [in]      PWSTR wszAlgID,
  [in]      UINT  uDataLen,
  [in]      BYTE  *pbDecodedData,
  [in, out] UINT  *puEncodedStringLen,
  [out]     PWSTR wszEncodedString
);