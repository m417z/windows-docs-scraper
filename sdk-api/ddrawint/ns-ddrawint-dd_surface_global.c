typedef struct _DD_SURFACE_GLOBAL {
  union {
    DWORD dwBlockSizeY;
    LONG  lSlicePitch;
  };
  union {
    LPVIDEOMEMORY lpVidMemHeap;
    DWORD         dwBlockSizeX;
    DWORD         dwUserMemSize;
  };
  FLATPTR       fpVidMem;
  union {
    LONG  lPitch;
    DWORD dwLinearSize;
  };
  LONG          yHint;
  LONG          xHint;
  DWORD         wHeight;
  DWORD         wWidth;
  ULONG_PTR     dwReserved1;
  DDPIXELFORMAT ddpfSurface;
  FLATPTR       fpHeapOffset;
  HANDLE        hCreatorProcess;
} *PDD_SURFACE_GLOBAL, DD_SURFACE_GLOBAL;