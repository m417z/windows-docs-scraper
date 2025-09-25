BOOL OEMQueryColorProfile(
        HANDLE    hPrinter,
        POEMUIOBJ poemuiobj,
        PDEVMODE  pPublicDM,
        PVOID     pOEMDM,
        ULONG     ulQueryMode,
  [out] VOID      *pvProfileData,
  [out] ULONG     *pcbProfileData,
  [out] FLONG     *pflProfileData
);