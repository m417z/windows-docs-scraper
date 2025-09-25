typedef struct _IRB_REQ_ISOCH_ALLOCATE_RESOURCES_W2K {
  ULONG  fulSpeed;
  ULONG  fulFlags;
  ULONG  nChannel;
  ULONG  nMaxBytesPerFrame;
  ULONG  nNumberOfBuffers;
  ULONG  nMaxBufferSize;
  ULONG  nQuadletsToStrip;
  HANDLE hResource;
} IRB_REQ_ISOCH_ALLOCATE_RESOURCES_W2K;