PFN_DrvGetDriverSetting PfnDrvgetdriversetting;

BOOL PfnDrvgetdriversetting(
                  PVOID pdriverobj,
                  PCSTR Feature,
                  PVOID pOutput,
                  DWORD cbSize,
  [out, optional] PDWORD pcbNeeded,
  [out, optional] PDWORD pdwOptionsReturned
)
{...}