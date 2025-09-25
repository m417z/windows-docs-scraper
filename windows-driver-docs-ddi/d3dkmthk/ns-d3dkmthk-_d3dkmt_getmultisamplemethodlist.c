typedef struct _D3DKMT_GETMULTISAMPLEMETHODLIST {
  [in]     D3DKMT_HANDLE                  hAdapter;
  [in]     D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]     UINT                           Width;
  [in]     UINT                           Height;
  [in]     D3DDDIFORMAT                   Format;
  [out]    D3DKMT_MULTISAMPLEMETHOD       *pMethodList;
  [in/out] UINT                           MethodCount;
} D3DKMT_GETMULTISAMPLEMETHODLIST;