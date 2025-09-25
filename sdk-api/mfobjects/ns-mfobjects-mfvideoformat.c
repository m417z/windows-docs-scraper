typedef struct _MFVIDEOFORMAT {
  DWORD                 dwSize;
  MFVideoInfo           videoInfo;
  GUID                  guidFormat;
  MFVideoCompressedInfo compressedInfo;
  MFVideoSurfaceInfo    surfaceInfo;
} MFVIDEOFORMAT;