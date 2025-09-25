typedef enum VMRPresentationFlags {
  VMRSample_SyncPoint = 0x1,
  VMRSample_Preroll = 0x2,
  VMRSample_Discontinuity = 0x4,
  VMRSample_TimeValid = 0x8,
  VMRSample_SrcDstRectsValid = 0x10
} ;