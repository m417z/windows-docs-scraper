typedef struct _DEVICE_MANAGE_DATA_SET_ATTRIBUTES {
  ULONG             Size;
  DEVICE_DSM_ACTION Action;
  ULONG             Flags;
  ULONG             ParameterBlockOffset;
  ULONG             ParameterBlockLength;
  ULONG             DataSetRangesOffset;
  ULONG             DataSetRangesLength;
} DEVICE_MANAGE_DATA_SET_ATTRIBUTES, *PDEVICE_MANAGE_DATA_SET_ATTRIBUTES, DEVICE_DSM_INPUT, *PDEVICE_DSM_INPUT;