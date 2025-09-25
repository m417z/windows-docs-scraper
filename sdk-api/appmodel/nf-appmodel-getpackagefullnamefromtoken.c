LONG GetPackageFullNameFromToken(
  [in]            HANDLE token,
  [in, out]       UINT32 *packageFullNameLength,
  [out, optional] PWSTR  packageFullName
);