typedef struct tagKS_VBI_FRAME_INFO {
  ULONG                  ExtendedHeaderSize;
  DWORD                  dwFrameFlags;
  LONGLONG               PictureNumber;
  LONGLONG               DropCount;
  DWORD                  dwSamplingFrequency;
  KS_TVTUNER_CHANGE_INFO TvTunerChangeInfo;
  KS_VBIINFOHEADER       VBIInfoHeader;
} KS_VBI_FRAME_INFO, *PKS_VBI_FRAME_INFO;