ULONG PerfQueryCounterSetRegistrationInfo(
  [in, optional]  LPCWSTR         szMachine,
  [in]            LPCGUID         pCounterSetId,
                  PerfRegInfoType requestCode,
                  DWORD           requestLangId,
  [out, optional] LPBYTE          pbRegInfo,
                  DWORD           cbRegInfo,
  [out]           LPDWORD         pcbRegInfoActual
);