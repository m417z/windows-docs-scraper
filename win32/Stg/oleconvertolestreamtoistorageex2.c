HRESULT OleConvertOLESTREAMToIStorageEx2(
  [in]  LPOLESTREAM polestm,
  [out] LPSTORAGE   pstg,
  [out] CLIPFORMAT  *pcfFormat,
  [out] LONG        *plwWidth,
  [out] LONG        *plHeight,
  [out] DWORD       *pdwSize,
  [out] LPSTGMEDIUM pmedium,
  [in]  DWORD           opt,
  [in]  PVOID           pvCallbackContext,
  [in]  OLESTREAMQUERYCONVERTOLELINKCALLBACK pQueryConvertOLELinkCallback
);