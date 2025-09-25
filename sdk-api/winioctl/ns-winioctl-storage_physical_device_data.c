typedef struct _STORAGE_PHYSICAL_DEVICE_DATA {
  DWORD                           DeviceId;
  DWORD                           Role;
  STORAGE_COMPONENT_HEALTH_STATUS HealthStatus;
  STORAGE_PROTOCOL_TYPE           CommandProtocol;
  STORAGE_SPEC_VERSION            SpecVersion;
  STORAGE_DEVICE_FORM_FACTOR      FormFactor;
  BYTE                            Vendor[8];
  BYTE                            Model[40];
  BYTE                            FirmwareRevision[16];
  DWORDLONG                       Capacity;
  BYTE                            PhysicalLocation[32];
  DWORD                           Reserved[2];
} STORAGE_PHYSICAL_DEVICE_DATA, *PSTORAGE_PHYSICAL_DEVICE_DATA;