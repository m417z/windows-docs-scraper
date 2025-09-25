HFDI DIAMONDAPI FDICreate(
  [in]      PFNALLOC pfnalloc,
  [in]      PFNFREE  pfnfree,
  [in]      PFNOPEN  pfnopen,
  [in]      PFNREAD  pfnread,
  [in]      PFNWRITE pfnwrite,
  [in]      PFNCLOSE pfnclose,
  [in]      PFNSEEK  pfnseek,
  [in]      int      cpuType,
  [in, out] PERF     perf
);