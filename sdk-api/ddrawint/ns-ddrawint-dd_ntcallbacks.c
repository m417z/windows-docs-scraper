typedef struct _DD_NTCALLBACKS {
  DWORD                dwSize;
  DWORD                dwFlags;
  PDD_FREEDRIVERMEMORY FreeDriverMemory;
  PDD_SETEXCLUSIVEMODE SetExclusiveMode;
  PDD_FLIPTOGDISURFACE FlipToGDISurface;
} DD_NTCALLBACKS, *PDD_NTCALLBACKS;