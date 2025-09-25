LSTATUS SHEnumValueA(
  [in]                HKEY    hkey,
  [in]                DWORD   dwIndex,
                      PSTR    pszValueName,
  [in, out, optional] LPDWORD pcchValueName,
  [out, optional]     LPDWORD pdwType,
                      void    *pvData,
  [in, out, optional] LPDWORD pcbData
);