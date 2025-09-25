LONG TTEmbedFontFromFileA(
  [in]           HDC            hDC,
  [in]           LPCSTR         szFontFileName,
  [in]           USHORT         usTTCIndex,
  [in]           ULONG          ulFlags,
  [in]           ULONG          ulCharSet,
  [out]          ULONG          *pulPrivStatus,
  [out]          ULONG          *pulStatus,
                 WRITEEMBEDPROC lpfnWriteToStream,
  [in]           LPVOID         lpvWriteStream,
  [in]           USHORT         *pusCharCodeSet,
  [in]           USHORT         usCharCodeCount,
  [in]           USHORT         usLanguage,
  [in, optional] TTEMBEDINFO    *pTTEmbedInfo
);