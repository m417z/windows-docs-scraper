typedef struct _STORAGE_PHYSICAL_DEVICE_DATA {
  ULONG                           DeviceId;
  ULONG                           Role;
  STORAGE_COMPONENT_HEALTH_STATUS HealthStatus;
  STORAGE_PROTOCOL_TYPE           CommandProtocol;
  STORAGE_SPEC_VERSION            SpecVersion;
  STORAGE_DEVICE_FORM_FACTOR      FormFactor;
  UCHAR                           Vendor[8];
  UCHAR                           Model[40];
  UCHAR                           FirmwareRevision[16];
  ULONGLONG                       Capacity;
  UCHAR                           PhysicalLocation[32];
  ULONG                           Reserved[2];
} STORAGE_PHYSICAL_DEVICE_DATA, *PSTORAGE_PHYSICAL_DEVICE_DATA;