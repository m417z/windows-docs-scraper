typedef struct tagKS_FRAME_INFO {
  ULONG    ExtendedHeaderSize;
  DWORD    dwFrameFlags;
  LONGLONG PictureNumber;
  LONGLONG DropCount;
  HANDLE   hDirectDraw;
  HANDLE   hSurfaceHandle;
  RECT     DirectDrawRect;
  union {
    LONG  lSurfacePitch;
    DWORD Reserved1;
  };
  DWORD    Reserved2;
  union {
    struct {
      DWORD Reserved3;
      DWORD Reserved4;
    };
    ULONGLONG FrameCompletionNumber;
  };
} KS_FRAME_INFO, *PKS_FRAME_INFO;