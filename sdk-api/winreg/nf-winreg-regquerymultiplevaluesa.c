LSTATUS RegQueryMultipleValuesA(
  [in]                HKEY     hKey,
  [out]               PVALENTA val_list,
  [in]                DWORD    num_vals,
  [out, optional]     LPSTR    lpValueBuf,
  [in, out, optional] LPDWORD  ldwTotsize
);