typedef struct {
  HWND                  hwnd;
  IContextMenuCB        *pcmcb;
  PCIDLIST_ABSOLUTE     pidlFolder;
  IShellFolder          *psf;
  UINT                  cidl;
  PCUITEMID_CHILD_ARRAY apidl;
  IUnknown              *punkAssociationInfo;
  UINT                  cKeys;
  const HKEY            *aKeys;
} DEFCONTEXTMENU;