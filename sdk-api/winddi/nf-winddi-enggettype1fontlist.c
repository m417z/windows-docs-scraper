ENGAPI BOOL EngGetType1FontList(
  [in]            HDEV          hdev,
  [out, optional] TYPE1_FONT    *pType1Buffer,
  [in]            ULONG         cjType1Buffer,
  [out]           PULONG        pulLocalFonts,
  [out]           PULONG        pulRemoteFonts,
  [out]           LARGE_INTEGER *pLastModified
);