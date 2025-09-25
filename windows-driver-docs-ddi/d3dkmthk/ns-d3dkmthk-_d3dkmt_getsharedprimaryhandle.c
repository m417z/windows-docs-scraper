typedef struct _D3DKMT_GETSHAREDPRIMARYHANDLE {
  [in]  D3DKMT_HANDLE                  hAdapter;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] D3DKMT_HANDLE                  hSharedPrimary;
} D3DKMT_GETSHAREDPRIMARYHANDLE;