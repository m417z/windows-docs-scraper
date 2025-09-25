typedef struct _D3DKMT_CREATE_OUTPUTDUPL {
        D3DKMT_HANDLE                  hAdapter;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  UINT                           KeyedMutexCount;
  [out] UINT                           RequiredKeyedMutexCount;
        D3DKMT_OUTPUTDUPL_KEYEDMUTEX   KeyedMutexs[OUTPUTDUPL_CREATE_MAX_KEYEDMUTXES];
        D3DKMT_OUTPUTDUPLCREATIONFLAGS Flags;
} D3DKMT_CREATE_OUTPUTDUPL;