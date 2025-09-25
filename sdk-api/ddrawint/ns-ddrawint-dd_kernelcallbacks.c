typedef struct DD_KERNELCALLBACKS {
  DWORD                      dwSize;
  DWORD                      dwFlags;
  PDD_KERNELCB_SYNCSURFACE   SyncSurfaceData;
  PDD_KERNELCB_SYNCVIDEOPORT SyncVideoPortData;
} DD_KERNELCALLBACKS, *PDD_KERNELCALLBACKS;