typedef struct tagDVD_VideoAttributes {
  BOOL                  fPanscanPermitted;
  BOOL                  fLetterboxPermitted;
  ULONG                 ulAspectX;
  ULONG                 ulAspectY;
  ULONG                 ulFrameRate;
  ULONG                 ulFrameHeight;
  DVD_VIDEO_COMPRESSION Compression;
  BOOL                  fLine21Field1InGOP;
  BOOL                  fLine21Field2InGOP;
  ULONG                 ulSourceResolutionX;
  ULONG                 ulSourceResolutionY;
  BOOL                  fIsSourceLetterboxed;
  BOOL                  fIsFilmMode;
} DVD_VideoAttributes;