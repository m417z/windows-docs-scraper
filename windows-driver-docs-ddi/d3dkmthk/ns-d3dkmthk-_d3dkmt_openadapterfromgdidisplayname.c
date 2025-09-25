typedef struct _D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME {
        WCHAR                          DeviceName[32];
  [out] D3DKMT_HANDLE                  hAdapter;
  [out] LUID                           AdapterLuid;
  [out] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
} D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME;