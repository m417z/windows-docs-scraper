typedef struct _D3DKMT_QUERYFSEBLOCK {
  LUID                           AdapterLuid;
  D3DKMT_HANDLE                  hAdapter;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  D3DKMT_QUERYFSEBLOCKFLAGS      Flags;
} D3DKMT_QUERYFSEBLOCK;