typedef struct PACKAGE_INFO {
  UINT32     reserved;
  UINT32     flags;
  PWSTR      path;
  PWSTR      packageFullName;
  PWSTR      packageFamilyName;
  PACKAGE_ID packageId;
} PACKAGE_INFO;