typedef struct tagOIFI {
  UINT   cb;
  BOOL   fMDIApp;
  HWND   hwndFrame;
  HACCEL haccel;
  UINT   cAccelEntries;
} OLEINPLACEFRAMEINFO, *LPOLEINPLACEFRAMEINFO;