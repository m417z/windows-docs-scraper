LONG TTEmbedFontEx(
  [in]           HDC            hDC,
  [in]           ULONG          ulFlags,
  [in]           ULONG          ulCharSet,
  [out]          ULONG          *pulPrivStatus,
  [out]          ULONG          *pulStatus,
                 WRITEEMBEDPROC lpfnWriteToStream,
  [in]           LPVOID         lpvWriteStream,
  [in]           ULONG          *pulCharCodeSet,
  [in]           USHORT         usCharCodeCount,
  [in]           USHORT         usLanguage,
  [in, optional] TTEMBEDINFO    *pTTEmbedInfo
);