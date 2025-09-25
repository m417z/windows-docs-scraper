struct GdiplusStartupInput {
  UINT32         GdiplusVersion;
  DebugEventProc DebugEventCallback;
  BOOL           SuppressBackgroundThread;
  BOOL           SuppressExternalCodecs;
  void           GdiplusStartupInput(
    DebugEventProc debugEventCallback,
    BOOL           suppressBackgroundThread,
    BOOL           suppressExternalCodecs
  );
};