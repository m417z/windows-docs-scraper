typedef union _PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS {
  struct {
    ULONG Undefined : 1;
    ULONG Reserved1 : 3;
    ULONG DataLinkProtocolError : 1;
    ULONG SurpriseDownError : 1;
    ULONG Reserved2 : 6;
    ULONG PoisonedTLP : 1;
    ULONG FlowControlProtocolError : 1;
    ULONG CompletionTimeout : 1;
    ULONG CompleterAbort : 1;
    ULONG UnexpectedCompletion : 1;
    ULONG ReceiverOverflow : 1;
    ULONG MalformedTLP : 1;
    ULONG ECRCError : 1;
    ULONG UnsupportedRequestError : 1;
    ULONG AcsViolation : 1;
    ULONG UncorrectableInternalError : 1;
    ULONG MCBlockedTlp : 1;
    ULONG AtomicOpEgressBlocked : 1;
    ULONG TlpPrefixBlocked : 1;
    ULONG PoisonedTlpEgressBlocked : 1;
    ULONG Reserved3 : 5;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS, *PPCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS;