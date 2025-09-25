typedef struct tagDEVICEDIALOGDATA2 {
  DWORD     cbSize;
  IWiaItem2 *pIWiaItemRoot;
  DWORD     dwFlags;
  HWND      hwndParent;
  BSTR      bstrFolderName;
  BSTR      bstrFilename;
  LONG      lNumFiles;
  BSTR      *pbstrFilePaths;
  IWiaItem2 *pWiaItem;
} DEVICEDIALOGDATA2, *LPDEVICEDIALOGDATA2, *PDEVICEDIALOGDATA2;