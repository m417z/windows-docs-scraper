typedef struct _CSFV {
  UINT              cbSize;
  IShellFolder      *pshf;
  IShellView        *psvOuter;
  PCIDLIST_ABSOLUTE pidl;
  LONG              lEvents;
  LPFNVIEWCALLBACK  pfnCallback;
  FOLDERVIEWMODE    fvm;
} CSFV, *LPCSFV;