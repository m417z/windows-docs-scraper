LSTATUS SHRegEnumUSValueW(
  [in]                HUSKEY          hUSkey,
  [in]                DWORD           dwIndex,
  [out]               LPWSTR          pszValueName,
  [in, out]           LPDWORD         pcchValueName,
  [out, optional]     LPDWORD         pdwType,
  [out, optional]     void            *pvData,
  [in, out, optional] LPDWORD         pcbData,
  [in]                SHREGENUM_FLAGS enumRegFlags
);