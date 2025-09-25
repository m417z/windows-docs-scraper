typedef struct _STORAGE_PHYSICAL_ADAPTER_DATA {
  DWORD                           AdapterId;
  STORAGE_COMPONENT_HEALTH_STATUS HealthStatus;
  STORAGE_PROTOCOL_TYPE           CommandProtocol;
  STORAGE_SPEC_VERSION            SpecVersion;
  BYTE                            Vendor[8];
  BYTE                            Model[40];
  BYTE                            FirmwareRevision[16];
  BYTE                            PhysicalLocation[32];
  BOOLEAN                         ExpanderConnected;
  BYTE                            Reserved0[3];
  DWORD                           Reserved1[3];
} STORAGE_PHYSICAL_ADAPTER_DATA, *PSTORAGE_PHYSICAL_ADAPTER_DATA;