NTSYSAPI NTSTATUS RtlQueryPackageIdentityEx(
  PVOID    TokenObject,
  PWSTR    PackageFullName,
  PSIZE_T  PackageSize,
  PWSTR    AppId,
  PSIZE_T  AppIdSize,
  LPGUID   DynamicId,
  PULONG64 Flags
);