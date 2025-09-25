int WPUGetProviderPath(
  [in]      LPGUID lpProviderId,
  [out]     WCHAR  *lpszProviderDllPath,
  [in, out] LPINT  lpProviderDllPathLen,
  [out]     LPINT  lpErrno
);