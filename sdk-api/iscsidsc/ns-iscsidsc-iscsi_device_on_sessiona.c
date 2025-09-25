typedef struct {
  CHAR                  InitiatorName[MAX_ISCSI_HBANAME_LEN];
  CHAR                  TargetName[MAX_ISCSI_NAME_LEN + 1];
  SCSI_ADDRESS          ScsiAddress;
  GUID                  DeviceInterfaceType;
  CHAR                  DeviceInterfaceName[MAX_PATH];
  CHAR                  LegacyName[MAX_PATH];
  STORAGE_DEVICE_NUMBER StorageDeviceNumber;
  DWORD                 DeviceInstance;
} ISCSI_DEVICE_ON_SESSIONA, *PISCSI_DEVICE_ON_SESSIONA;