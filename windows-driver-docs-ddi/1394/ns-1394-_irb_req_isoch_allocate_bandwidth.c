typedef struct _IRB_REQ_ISOCH_ALLOCATE_BANDWIDTH {
  ULONG  nMaxBytesPerFrameRequested;
  ULONG  fulSpeed;
  HANDLE hBandwidth;
  ULONG  BytesPerFrameAvailable;
  ULONG  SpeedSelected;
  ULONG  nBandwidthUnitsRequired;
} IRB_REQ_ISOCH_ALLOCATE_BANDWIDTH;