typedef struct _DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT {
  ULONG             Size;
  DEVICE_DSM_ACTION Action;
  ULONG             Flags;
  ULONG             OperationStatus;
  ULONG             ExtendedError;
  ULONG             TargetDetailedError;
  ULONG             ReservedStatus;
  ULONG             OutputBlockOffset;
  ULONG             OutputBlockLength;
} DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT, *PDEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT, DEVICE_DSM_OUTPUT, *PDEVICE_DSM_OUTPUT;