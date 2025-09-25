DWORD DrvSplDeviceCaps(
                  HANDLE   hPrinter,
  [in]            PWSTR    pszDeviceName,
                  WORD     Capability,
  [out, optional] PVOID    pOutput,
                  DWORD    cchBufSize,
  [in, optional]  PDEVMODE pDevmode
);