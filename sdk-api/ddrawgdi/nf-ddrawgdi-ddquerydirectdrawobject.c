BOOL DdQueryDirectDrawObject(
  LPDDRAWI_DIRECTDRAW_GBL    pDirectDrawGlobal,
  LPDDHALINFO                pHalInfo,
  LPDDHAL_DDCALLBACKS        pDDCallbacks,
  LPDDHAL_DDSURFACECALLBACKS pDDSurfaceCallbacks,
  LPDDHAL_DDPALETTECALLBACKS pDDPaletteCallbacks,
  LPD3DHAL_CALLBACKS         pD3dCallbacks,
  LPD3DHAL_GLOBALDRIVERDATA  pD3dDriverData,
  LPDDHAL_DDEXEBUFCALLBACKS  pD3dBufferCallbacks,
  LPDDSURFACEDESC            pD3dTextureFormats,
  LPDWORD                    pdwFourCC,
  LPVIDMEM                   pvmList
);