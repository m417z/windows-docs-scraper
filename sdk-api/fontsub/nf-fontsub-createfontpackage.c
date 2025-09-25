unsigned long CreateFontPackage(
  [in]  const unsigned char  *puchSrcBuffer,
  [in]  const unsigned long  ulSrcBufferSize,
  [out] unsigned char        **ppuchFontPackageBuffer,
  [out] unsigned long        *pulFontPackageBufferSize,
  [out] unsigned long        *pulBytesWritten,
  [in]  const unsigned short usFlag,
  [in]  const unsigned short usTTCIndex,
  [in]  const unsigned short usSubsetFormat,
  [in]  const unsigned short usSubsetLanguage,
  [in]  const unsigned short usSubsetPlatform,
  [in]  const unsigned short usSubsetEncoding,
  [in]  const unsigned short *pusSubsetKeepList,
  [in]  const unsigned short usSubsetListCount,
  [in]  CFP_ALLOCPROC        lpfnAllocate,
  [in]  CFP_REALLOCPROC      lpfnReAllocate,
  [in]  CFP_FREEPROC         lpfnFree,
  [in]  void                 *lpvReserved
);