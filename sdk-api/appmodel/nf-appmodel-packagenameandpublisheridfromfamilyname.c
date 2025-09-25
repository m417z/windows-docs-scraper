LONG PackageNameAndPublisherIdFromFamilyName(
  [in]            PCWSTR packageFamilyName,
  [in, out]       UINT32 *packageNameLength,
  [out, optional] PWSTR  packageName,
  [in, out]       UINT32 *packagePublisherIdLength,
  [out, optional] PWSTR  packagePublisherId
);