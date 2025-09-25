PFN_DrvGetStandardVariable PfnDrvgetstandardvariable;

BOOL PfnDrvgetstandardvariable(
  PDEVOBJ pdevobj,
  DWORD dwIndex,
  PVOID pBuffer,
  DWORD cbSize,
  PDWORD pcbNeeded
)
{...}