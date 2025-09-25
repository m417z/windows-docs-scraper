LONG FindPackagesByPackageFamily(
  [in]            PCWSTR packageFamilyName,
  [in]            UINT32 packageFilters,
  [in, out]       UINT32 *count,
  [out, optional] PWSTR  *packageFullNames,
  [in, out]       UINT32 *bufferLength,
  [out, optional] WCHAR  *buffer,
  [out, optional] UINT32 *packageProperties
);