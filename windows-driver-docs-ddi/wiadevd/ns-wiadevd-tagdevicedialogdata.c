typedef struct tagDEVICEDIALOGDATA {
  DWORD    cbSize;
  HWND     hwndParent;
  IWiaItem *pIWiaItemRoot;
  DWORD    dwFlags;
  LONG     lIntent;
  LONG     lItemCount;
  IWiaItem **ppWiaItems;
} DEVICEDIALOGDATA, *LPDEVICEDIALOGDATA, *PDEVICEDIALOGDATA;