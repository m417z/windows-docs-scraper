SHSTDAPI SHDoDragDrop(
  [in]  HWND        hwnd,
  [in]  IDataObject *pdata,
  [in]  IDropSource *pdsrc,
  [in]  DWORD       dwEffect,
  [out] DWORD       *pdwEffect
);