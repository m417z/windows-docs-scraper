BOOL DrvQueryColorProfile(
        HANDLE    hPrinter,
  [in]  PDEVMODEW pdevmode,
        ULONG     ulQueryMode,
  [out] VOID      *pvProfileData,
  [out] ULONG     *pcbProfileData,
  [out] FLONG     *pflProfileData
);