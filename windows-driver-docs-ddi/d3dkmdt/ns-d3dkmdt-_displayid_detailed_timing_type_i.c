typedef struct _DISPLAYID_DETAILED_TIMING_TYPE_I {
  struct {
    [in] ULONG PixelClock : 24;
    [in] ULONG AspectRatio : 3;
    [in] ULONG Reserved : 1;
    [in] ULONG ScanningType : 1;
    [in] ULONG StereoMode : 2;
         ULONG PreferredTiming : 1;
  };
  [in] USHORT HorizontalActivePixels;
  [in] USHORT HorizontalBlankPixels;
  struct {
    [in] USHORT HorizontalFrontPorch : 15;
    [in] USHORT HorizontalSyncPolarity : 1;
  };
  [in] USHORT HorizontalSyncWidth;
  [in] USHORT VerticalActiveLines;
  [in] USHORT VerticalBlankLines;
  struct {
    [in] USHORT VerticalFrontPorch : 15;
    [in] USHORT VerticalSyncPolarity : 1;
  };
  [in] USHORT VerticalSyncWidth;
} DISPLAYID_DETAILED_TIMING_TYPE_I;