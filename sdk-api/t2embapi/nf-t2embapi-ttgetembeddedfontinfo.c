LONG TTGetEmbeddedFontInfo(
  [in]  ULONG         ulFlags,
  [out] ULONG         *pulPrivStatus,
  [in]  ULONG         ulPrivs,
  [out] ULONG         *pulStatus,
        READEMBEDPROC lpfnReadFromStream,
  [in]  LPVOID        lpvReadStream,
  [in]  TTLOADINFO    *pTTLoadInfo
);