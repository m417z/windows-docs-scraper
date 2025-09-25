typedef struct _D3DDDICB_GETMULTISAMPLEMETHODLIST {
  [in]     D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]     UINT                           Width;
  [in]     UINT                           Height;
  [in]     D3DDDIFORMAT                   Format;
  [out]    D3DDDI_MULTISAMPLINGMETHOD     *pMethodList;
  [in/out] UINT                           MethodCount;
} D3DDDICB_GETMULTISAMPLEMETHODLIST;