typedef struct _DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT {
  DWORD             Size;
  DEVICE_DSM_ACTION Action;
  DWORD             Flags;
  DWORD             OperationStatus;
  DWORD             ExtendedError;
  DWORD             TargetDetailedError;
  DWORD             ReservedStatus;
  DWORD             OutputBlockOffset;
  DWORD             OutputBlockLength;
} DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT, *PDEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT, DEVICE_DSM_OUTPUT, *PDEVICE_DSM_OUTPUT;