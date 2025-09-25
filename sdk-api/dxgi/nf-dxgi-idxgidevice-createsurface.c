HRESULT CreateSurface(
  [in]           const DXGI_SURFACE_DESC    *pDesc,
                 UINT                       NumSurfaces,
                 DXGI_USAGE                 Usage,
  [in, optional] const DXGI_SHARED_RESOURCE *pSharedResource,
  [out]          IDXGISurface               **ppSurface
);