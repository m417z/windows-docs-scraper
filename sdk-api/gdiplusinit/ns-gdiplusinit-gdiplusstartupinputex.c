struct GdiplusStartupInputEx : GdiplusStartupInput {
  INT  StartupParameters;
  void GdiplusStartupInputEx(
    INT            startupParameters,
    DebugEventProc debugEventCallback,
    BOOL           suppressBackgroundThread,
    BOOL           suppressExternalCodecs
  );
  void GdiplusStartupInputEx(
    Version        gdiplusVersion,
    INT            startupParameters,
    DebugEventProc debugEventCallback,
    BOOL           suppressBackgroundThread,
    BOOL           suppressExternalCodecs
  );
};