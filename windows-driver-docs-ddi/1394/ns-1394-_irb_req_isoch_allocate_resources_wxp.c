typedef struct _IRB_REQ_ISOCH_ALLOCATE_RESOURCES_WXP {
  ULONG          fulSpeed;
  ULONG          fulFlags;
  ULONG          nChannel;
  ULONG          nMaxBytesPerFrame;
  ULONG          nNumberOfBuffers;
  ULONG          nMaxBufferSize;
  ULONG          nQuadletsToStrip;
  HANDLE         hResource;
  ULARGE_INTEGER ChannelMask;
} IRB_REQ_ISOCH_ALLOCATE_RESOURCES_WXP;