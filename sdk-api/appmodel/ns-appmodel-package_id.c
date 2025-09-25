typedef struct PACKAGE_ID {
  UINT32          reserved;
  UINT32          processorArchitecture;
  PACKAGE_VERSION version;
  PWSTR           name;
  PWSTR           publisher;
  PWSTR           resourceId;
  PWSTR           publisherId;
} PACKAGE_ID;