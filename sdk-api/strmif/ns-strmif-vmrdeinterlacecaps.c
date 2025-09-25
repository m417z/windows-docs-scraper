typedef struct _VMRDeinterlaceCaps {
  DWORD              dwSize;
  DWORD              dwNumPreviousOutputFrames;
  DWORD              dwNumForwardRefSamples;
  DWORD              dwNumBackwardRefSamples;
  VMRDeinterlaceTech DeinterlaceTechnology;
} VMRDeinterlaceCaps;