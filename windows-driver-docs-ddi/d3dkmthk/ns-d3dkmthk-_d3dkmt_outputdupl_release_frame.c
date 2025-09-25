typedef struct _D3DKMT_OUTPUTDUPL_RELEASE_FRAME {
  [in] D3DKMT_HANDLE                  hAdapter;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
       UINT                           NextKeyMutexIdx;
} D3DKMT_OUTPUTDUPL_RELEASE_FRAME;