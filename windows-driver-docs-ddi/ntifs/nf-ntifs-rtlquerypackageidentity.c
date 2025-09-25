NTSYSAPI NTSTATUS RtlQueryPackageIdentity(
  PVOID    TokenObject,
  PWSTR    PackageFullName,
  PSIZE_T  PackageSize,
  PWSTR    AppId,
  PSIZE_T  AppIdSize,
  PBOOLEAN Packaged
);