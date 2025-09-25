BOOL DIAMONDAPI FDICopy(
  [in]           HFDI          hfdi,
  [in]           LPSTR         pszCabinet,
  [in]           LPSTR         pszCabPath,
  [in]           int           flags,
  [in]           PFNFDINOTIFY  pfnfdin,
  [in]           PFNFDIDECRYPT pfnfdid,
  [in, optional] void          *pvUser
);