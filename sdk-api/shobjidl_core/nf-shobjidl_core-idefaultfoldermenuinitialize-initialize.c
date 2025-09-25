HRESULT Initialize(
  [in]           HWND                  hwnd,
  [in, optional] IContextMenuCB        *pcmcb,
  [in, optional] PCIDLIST_ABSOLUTE     pidlFolder,
  [in, optional] IShellFolder          *psf,
  [in]           UINT                  cidl,
  [in]           PCUITEMID_CHILD_ARRAY apidl,
  [in, optional] IUnknown              *punkAssociation,
  [in]           UINT                  cKeys,
  [in, optional] const HKEY            *aKeys
);