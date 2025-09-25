SHSTDAPI CDefFolderMenu_Create2(
  [in, optional] PCIDLIST_ABSOLUTE     pidlFolder,
  [in, optional] HWND                  hwnd,
                 UINT                  cidl,
  [in, optional] PCUITEMID_CHILD_ARRAY apidl,
  [in, optional] IShellFolder          *psf,
  [in, optional] LPFNDFMCALLBACK       pfn,
                 UINT                  nKeys,
  [in, optional] const HKEY            *ahkeys,
  [out]          IContextMenu          **ppcm
);