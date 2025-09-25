LSTATUS SHRegEnumUSValueA(
  [in]                HUSKEY          hUSkey,
  [in]                DWORD           dwIndex,
  [out]               LPSTR           pszValueName,
  [in, out]           LPDWORD         pcchValueName,
  [out, optional]     LPDWORD         pdwType,
  [out, optional]     void            *pvData,
  [in, out, optional] LPDWORD         pcbData,
  [in]                SHREGENUM_FLAGS enumRegFlags
);