typedef struct _IRB_REQ_ISOCH_FREE_BANDWIDTH {
  HANDLE hBandwidth;
  ULONG  nMaxBytesPerFrameRequested;
  ULONG  fulSpeed;
  ULONG  BytesPerFrameAvailable;
  ULONG  SpeedSelected;
  ULONG  nBandwidthUnitsRequired;
} IRB_REQ_ISOCH_FREE_BANDWIDTH;