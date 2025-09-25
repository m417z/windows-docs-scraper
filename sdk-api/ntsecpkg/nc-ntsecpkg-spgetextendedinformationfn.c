SpGetExtendedInformationFn Spgetextendedinformationfn;

NTSTATUS Spgetextendedinformationfn(
  [in]  SECPKG_EXTENDED_INFORMATION_CLASS Class,
  [out] PSECPKG_EXTENDED_INFORMATION *ppInformation
)
{...}