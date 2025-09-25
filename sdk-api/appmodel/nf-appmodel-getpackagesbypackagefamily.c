LONG GetPackagesByPackageFamily(
  [in]            PCWSTR packageFamilyName,
  [in, out]       UINT32 *count,
  [out, optional] PWSTR  *packageFullNames,
  [in, out]       UINT32 *bufferLength,
  [out, optional] WCHAR  *buffer
);