LONG ParseApplicationUserModelId(
  [in]            PCWSTR applicationUserModelId,
  [in, out]       UINT32 *packageFamilyNameLength,
  [out, optional] PWSTR  packageFamilyName,
  [in, out]       UINT32 *packageRelativeApplicationIdLength,
  [out, optional] PWSTR  packageRelativeApplicationId
);