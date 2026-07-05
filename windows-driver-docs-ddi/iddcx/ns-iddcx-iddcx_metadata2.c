struct IDDCX_METADATA2 {
  UINT                        Size;
  IDDCX_METADATA2_VALID_FLAGS ValidFlags;
  UINT                        PresentationFrameNumber;
  UINT                        DirtyRectCount;
  BOOL                        HwProtectedSurface;
  UINT64                      PresentDisplayQPCTime;
  IDXGIResource               *pSurface;
  DXGI_COLOR_SPACE_TYPE       SurfaceColorSpace;
  UINT                        SdrWhiteLevel;
  IDDCX_SYSTEM_BUFFER_INFO    SystemBufferInfo;
  IDDCX_HDR10_FRAME_METADATA  Hdr10FrameMetaData;
};