HRESULT OleConvertOLESTREAMToIStorageEx(
  [in]  LPOLESTREAM polestm,
  [out] LPSTORAGE   pstg,
  [out] CLIPFORMAT  *pcfFormat,
  [out] LONG        *plwWidth,
  [out] LONG        *plHeight,
  [out] DWORD       *pdwSize,
  [out] LPSTGMEDIUM pmedium
);