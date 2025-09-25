typedef struct _D3DKMT_SETFSEBLOCK {
  LUID                           AdapterLuid;
  D3DKMT_HANDLE                  hAdapter;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  D3DKMT_SETFSEBLOCKFLAGS        Flags;
} D3DKMT_SETFSEBLOCK;