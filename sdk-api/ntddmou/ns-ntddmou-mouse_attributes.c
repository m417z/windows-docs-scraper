typedef struct _MOUSE_ATTRIBUTES {
  USHORT MouseIdentifier;
  USHORT NumberOfButtons;
  USHORT SampleRate;
  ULONG  InputDataQueueLength;
} MOUSE_ATTRIBUTES, *PMOUSE_ATTRIBUTES;