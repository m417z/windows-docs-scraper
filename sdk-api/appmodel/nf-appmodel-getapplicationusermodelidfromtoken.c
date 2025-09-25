LONG GetApplicationUserModelIdFromToken(
  [in]      HANDLE token,
  [in, out] UINT32 *applicationUserModelIdLength,
  [out]     PWSTR  applicationUserModelId
);