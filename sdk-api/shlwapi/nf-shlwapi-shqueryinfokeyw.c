LSTATUS SHQueryInfoKeyW(
  [in]            HKEY    hkey,
  [out, optional] LPDWORD pcSubKeys,
  [out, optional] LPDWORD pcchMaxSubKeyLen,
  [out, optional] LPDWORD pcValues,
  [out, optional] LPDWORD pcchMaxValueNameLen
);