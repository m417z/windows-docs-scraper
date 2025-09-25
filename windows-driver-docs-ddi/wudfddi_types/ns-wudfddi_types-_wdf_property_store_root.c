typedef struct _WDF_PROPERTY_STORE_ROOT {
  ULONG                         LengthCb;
  WDF_PROPERTY_STORE_ROOT_CLASS RootClass;
  union {
    struct {
      PCWSTR ServiceName;
    } HardwareKey;
    struct {
      LPCGUID InterfaceGUID;
      PCWSTR  ReferenceString;
    } DeviceInterfaceKey;
    struct {
      PCWSTR LegacyMapName;
    } LegacyHardwareKey;
  } Qualifier;
} WDF_PROPERTY_STORE_ROOT, *PWDF_PROPERTY_STORE_ROOT;