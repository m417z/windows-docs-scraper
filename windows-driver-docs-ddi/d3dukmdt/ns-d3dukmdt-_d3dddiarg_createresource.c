typedef struct _D3DDDIARG_CREATERESOURCE {
  [in]     D3DDDIFORMAT                   Format;
  [in]     D3DDDI_POOL                    Pool;
  [in]     D3DDDIMULTISAMPLE_TYPE         MultisampleType;
  [in]     UINT                           MultisampleQuality;
  [in]     const D3DDDI_SURFACEINFO       *pSurfList;
  [in]     UINT                           SurfCount;
  [in]     UINT                           MipLevels;
  [in]     UINT                           Fvf;
  [in]     D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]     D3DDDI_RATIONAL                RefreshRate;
  [in/out] HANDLE                         hResource;
  [in]     D3DDDI_RESOURCEFLAGS           Flags;
  [in]     D3DDDI_ROTATION                Rotation;
} D3DDDIARG_CREATERESOURCE;