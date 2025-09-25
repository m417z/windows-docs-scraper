unsigned long MergeFontPackage(
  [in]  const unsigned char  *puchMergeFontBuffer,
  [in]  const unsigned long  ulMergeFontBufferSize,
  [in]  const unsigned char  *puchFontPackageBuffer,
  [in]  const unsigned long  ulFontPackageBufferSize,
  [out] unsigned char        **ppuchDestBuffer,
  [out] unsigned long        *pulDestBufferSize,
  [out] unsigned long        *pulBytesWritten,
  [in]  const unsigned short usMode,
  [in]  CFP_ALLOCPROC        lpfnAllocate,
  [in]  CFP_REALLOCPROC      lpfnReAllocate,
  [in]  CFP_FREEPROC         lpfnFree,
  [in]  void                 *lpvReserved
);