typedef struct _WHEA_AER_ENDPOINT_DESCRIPTOR {
  USHORT                        Type;
  BOOLEAN                       Enabled;
  UCHAR                         Reserved;
  ULONG                         BusNumber;
  WHEA_PCI_SLOT_NUMBER          Slot;
  USHORT                        DeviceControl;
  AER_ENDPOINT_DESCRIPTOR_FLAGS Flags;
  ULONG                         UncorrectableErrorMask;
  ULONG                         UncorrectableErrorSeverity;
  ULONG                         CorrectableErrorMask;
  ULONG                         AdvancedCapsAndControl;
} WHEA_AER_ENDPOINT_DESCRIPTOR, *PWHEA_AER_ENDPOINT_DESCRIPTOR;