typedef struct _DEVICE_MANAGE_DATA_SET_ATTRIBUTES {
  DWORD             Size;
  DEVICE_DSM_ACTION Action;
  DWORD             Flags;
  DWORD             ParameterBlockOffset;
  DWORD             ParameterBlockLength;
  DWORD             DataSetRangesOffset;
  DWORD             DataSetRangesLength;
} DEVICE_MANAGE_DATA_SET_ATTRIBUTES, *PDEVICE_MANAGE_DATA_SET_ATTRIBUTES, DEVICE_DSM_INPUT, *PDEVICE_DSM_INPUT;