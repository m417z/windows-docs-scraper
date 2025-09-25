typedef struct {
  WCHAR                 InitiatorName[MAX_ISCSI_HBANAME_LEN];
  WCHAR                 TargetName[MAX_ISCSI_NAME_LEN + 1];
  SCSI_ADDRESS          ScsiAddress;
  GUID                  DeviceInterfaceType;
  WCHAR                 DeviceInterfaceName[MAX_PATH];
  WCHAR                 LegacyName[MAX_PATH];
  STORAGE_DEVICE_NUMBER StorageDeviceNumber;
  DWORD                 DeviceInstance;
} ISCSI_DEVICE_ON_SESSIONW, *PISCSI_DEVICE_ON_SESSIONW;