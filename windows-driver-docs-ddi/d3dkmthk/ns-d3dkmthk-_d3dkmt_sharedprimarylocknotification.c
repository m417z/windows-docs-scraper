typedef struct _D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION {
  [in] LUID                           AdapterLuid;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] RECTL                          LockRect;
} D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION;