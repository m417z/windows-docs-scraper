HRESULT QueryColorProfile(
  HANDLE    hPrinter,
  POEMUIOBJ poemuiobj,
  PDEVMODE  pPublicDM,
  PVOID     pOEMDM,
  ULONG     ulQueryMode,
  VOID      *pvProfileData,
  ULONG     *pcbProfileData,
  FLONG     *pflProfileData
);