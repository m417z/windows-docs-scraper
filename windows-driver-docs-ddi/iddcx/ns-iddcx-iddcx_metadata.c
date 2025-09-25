struct IDDCX_METADATA {
  UINT          Size;
  UINT          PresentationFrameNumber;
  UINT          DirtyRectCount;
  UINT          MoveRegionCount;
  BOOL          HwProtectedSurface;
  UINT64        PresentDisplayQPCTime;
  IDXGIResource *pSurface;
};