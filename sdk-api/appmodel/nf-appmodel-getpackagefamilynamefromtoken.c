LONG GetPackageFamilyNameFromToken(
  [in]            HANDLE token,
  [in, out]       UINT32 *packageFamilyNameLength,
  [out, optional] PWSTR  packageFamilyName
);