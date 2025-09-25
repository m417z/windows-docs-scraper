typedef struct _PCI_EXPRESS_BRIDGE_AER_CAPABILITY {
  PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER        Header;
  PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS        UncorrectableErrorStatus;
  PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK          UncorrectableErrorMask;
  PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY      UncorrectableErrorSeverity;
  PCI_EXPRESS_CORRECTABLE_ERROR_STATUS          CorrectableErrorStatus;
  PCI_EXPRESS_CORRECTABLE_ERROR_MASK            CorrectableErrorMask;
  PCI_EXPRESS_AER_CAPABILITIES                  CapabilitiesAndControl;
  ULONG                                         HeaderLog[4];
  PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS    SecUncorrectableErrorStatus;
  PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK      SecUncorrectableErrorMask;
  PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY  SecUncorrectableErrorSeverity;
  PCI_EXPRESS_SEC_AER_CAPABILITIES              SecCapabilitiesAndControl;
  ULONG                                         SecHeaderLog[4];
} PCI_EXPRESS_BRIDGE_AER_CAPABILITY, *PPCI_EXPRESS_BRIDGE_AER_CAPABILITY;