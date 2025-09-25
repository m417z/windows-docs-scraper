LONG TTLoadEmbeddedFont(
  [out]          HANDLE        *phFontReference,
  [in]           ULONG         ulFlags,
  [out]          ULONG         *pulPrivStatus,
  [in]           ULONG         ulPrivs,
  [out]          ULONG         *pulStatus,
  [in]           READEMBEDPROC lpfnReadFromStream,
  [in]           LPVOID        lpvReadStream,
  [in, optional] LPWSTR        szWinFamilyName,
  [in, optional] LPSTR         szMacFamilyName,
  [in, optional] TTLOADINFO    *pTTLoadInfo
);