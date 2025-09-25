typedef struct _VIDEO_WIN32K_CALLBACKS {
  IN PVOID                 PhysDisp;
  IN PVIDEO_WIN32K_CALLOUT Callout;
  OUT ULONG                bACPI;
  OUT HANDLE               pPhysDeviceObject;
  OUT ULONG                DualviewFlags;
} VIDEO_WIN32K_CALLBACKS, *PVIDEO_WIN32K_CALLBACKS;