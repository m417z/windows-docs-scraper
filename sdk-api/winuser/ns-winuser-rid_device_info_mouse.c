typedef struct tagRID_DEVICE_INFO_MOUSE {
  DWORD dwId;
  DWORD dwNumberOfButtons;
  DWORD dwSampleRate;
  BOOL  fHasHorizontalWheel;
} RID_DEVICE_INFO_MOUSE, *PRID_DEVICE_INFO_MOUSE;