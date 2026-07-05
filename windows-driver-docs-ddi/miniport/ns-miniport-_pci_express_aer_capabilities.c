typedef union _PCI_EXPRESS_AER_CAPABILITIES {
  struct {
    ULONG FirstErrorPointer : 5;
    ULONG ECRCGenerationCapable : 1;
    ULONG ECRCGenerationEnable : 1;
    ULONG ECRCCheckCapable : 1;
    ULONG ECRCCheckEnable : 1;
    ULONG MultipleHeaderRecordingCapable : 1;
    ULONG MultipleHeaderRecordingEnable : 1;
    ULONG TlpPrefixLogPresent : 1;
    ULONG CompletionTimeoutPrefixHeaderLogCapable : 1;
    ULONG HeaderLogSize : 5;
    ULONG LoggedTlpWasFlitMode : 1;
    ULONG LoggedTlpSize : 5;
    ULONG Reserved : 8;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_AER_CAPABILITIES, *PPCI_EXPRESS_AER_CAPABILITIES;