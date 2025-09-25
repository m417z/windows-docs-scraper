typedef struct _WHEA_AER_ROOTPORT_DESCRIPTOR {
  USHORT                        Type;
  BOOLEAN                       Enabled;
  UCHAR                         Reserved;
  ULONG                         BusNumber;
  WHEA_PCI_SLOT_NUMBER          Slot;
  USHORT                        DeviceControl;
  AER_ROOTPORT_DESCRIPTOR_FLAGS Flags;
  ULONG                         UncorrectableErrorMask;
  ULONG                         UncorrectableErrorSeverity;
  ULONG                         CorrectableErrorMask;
  ULONG                         AdvancedCapsAndControl;
  ULONG                         RootErrorCommand;
} WHEA_AER_ROOTPORT_DESCRIPTOR, *PWHEA_AER_ROOTPORT_DESCRIPTOR;