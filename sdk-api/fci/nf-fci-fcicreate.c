HFCI DIAMONDAPI FCICreate(
  [in, out]      PERF              perf,
  [in]           PFNFCIFILEPLACED  pfnfcifp,
  [in]           PFNFCIALLOC       pfna,
  [in]           PFNFCIFREE        pfnf,
  [in]           PFNFCIOPEN        pfnopen,
  [in]           PFNFCIREAD        pfnread,
  [in]           PFNFCIWRITE       pfnwrite,
  [in]           PFNFCICLOSE       pfnclose,
  [in]           PFNFCISEEK        pfnseek,
  [in]           PFNFCIDELETE      pfndelete,
  [in]           PFNFCIGETTEMPFILE pfnfcigtf,
  [in]           PCCAB             pccab,
  [in, optional] void              *pv
);