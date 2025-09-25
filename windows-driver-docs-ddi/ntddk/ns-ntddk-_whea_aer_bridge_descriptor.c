typedef struct _WHEA_AER_BRIDGE_DESCRIPTOR {
  USHORT                      Type;
  BOOLEAN                     Enabled;
  UCHAR                       Reserved;
  ULONG                       BusNumber;
  WHEA_PCI_SLOT_NUMBER        Slot;
  USHORT                      DeviceControl;
  AER_BRIDGE_DESCRIPTOR_FLAGS Flags;
  ULONG                       UncorrectableErrorMask;
  ULONG                       UncorrectableErrorSeverity;
  ULONG                       CorrectableErrorMask;
  ULONG                       AdvancedCapsAndControl;
  ULONG                       SecondaryUncorrectableErrorMask;
  ULONG                       SecondaryUncorrectableErrorSev;
  ULONG                       SecondaryCapsAndControl;
} WHEA_AER_BRIDGE_DESCRIPTOR, *PWHEA_AER_BRIDGE_DESCRIPTOR;