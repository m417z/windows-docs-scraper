LONG FormatApplicationUserModelId(
  [in]            PCWSTR packageFamilyName,
  [in]            PCWSTR packageRelativeApplicationId,
  [in, out]       UINT32 *applicationUserModelIdLength,
  [out, optional] PWSTR  applicationUserModelId
);