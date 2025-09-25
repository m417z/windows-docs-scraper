DRMEXPORT HRESULT UDAPICALL DRMDecode(
  [in]  PWSTR wszAlgID,
  [in]  PWSTR wszEncodedString,
  [in]  UINT  *puDecodedDataLen,
  [out] BYTE  *pbDecodedData
);