typedef struct _BDA_PIN_PAIRING {
  ULONG       ulInputPin;
  ULONG       ulOutputPin;
  ULONG       ulcMaxInputsPerOutput;
  ULONG       ulcMinInputsPerOutput;
  ULONG       ulcMaxOutputsPerInput;
  ULONG       ulcMinOutputsPerInput;
  ULONG       ulcTopologyJoints;
  const ULONG *pTopologyJoints;
} BDA_PIN_PAIRING, *PBDA_PIN_PAIRING;