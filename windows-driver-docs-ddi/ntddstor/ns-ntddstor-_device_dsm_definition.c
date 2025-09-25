typedef struct _DEVICE_DSM_DEFINITION {
  DEVICE_DSM_ACTION Action;
  BOOLEAN           SingleRange;
  ULONG             ParameterBlockAlignment;
  ULONG             ParameterBlockLength;
  BOOLEAN           HasOutput;
  ULONG             OutputBlockAlignment;
  ULONG             OutputBlockLength;
} DEVICE_DSM_DEFINITION, *PDEVICE_DSM_DEFINITION;