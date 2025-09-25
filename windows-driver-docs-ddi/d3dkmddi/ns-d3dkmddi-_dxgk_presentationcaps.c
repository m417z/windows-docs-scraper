typedef struct _DXGK_PRESENTATIONCAPS {
  union {
    struct {
      UINT NoScreenToScreenBlt : 1;
      UINT NoOverlapScreenBlt : 1;
      UINT SupportKernelModeCommandBuffer : 1;
      UINT NoSameBitmapAlphaBlend : 1;
      UINT NoSameBitmapStretchBlt : 1;
      UINT NoSameBitmapTransparentBlt : 1;
      UINT NoSameBitmapOverlappedAlphaBlend : 1;
      UINT NoSameBitmapOverlappedStretchBlt : 1;
      UINT DriverSupportsCddDwmInterop : 1;
      UINT Reserved0 : 1;
      UINT AlignmentShift : 4;
      UINT MaxTextureWidthShift : 3;
      UINT MaxTextureHeightShift : 3;
      UINT SupportAllBltRops : 1;
      UINT SupportMirrorStretchBlt : 1;
      UINT SupportMonoStretchBltModes : 1;
      UINT StagingRectStartPitchAligned : 1;
      UINT NoSameBitmapBitBlt : 1;
      UINT NoSameBitmapOverlappedBitBlt : 1;
      UINT Reserved1 : 1;
      UINT NoTempSurfaceForClearTypeBlend : 1;
      UINT SupportSoftwareDeviceBitmaps : 1;
      UINT NoCacheCoherentApertureMemory : 1;
      UINT SupportLinearHeap : 1;
#if ...
      UINT Reserved : 1;
#else
      UINT Reserved : 4;
#endif
    };
         UINT Value;
  };
} DXGK_PRESENTATIONCAPS;