LSTATUS RegQueryMultipleValuesW(
  [in]                HKEY     hKey,
  [out]               PVALENTW val_list,
  [in]                DWORD    num_vals,
  [out, optional]     LPWSTR   lpValueBuf,
  [in, out, optional] LPDWORD  ldwTotsize
);