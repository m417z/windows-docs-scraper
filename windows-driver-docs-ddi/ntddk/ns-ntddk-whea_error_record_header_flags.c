typedef union _WHEA_ERROR_RECORD_HEADER_FLAGS {
  struct {
    ULONG Recovered : 1;
    ULONG PreviousError : 1;
    ULONG Simulated : 1;
    ULONG DeviceDriver : 1;
    ULONG CriticalEvent : 1;
    ULONG PersistPfn : 1;
    ULONG SectionsTruncated : 1;
    ULONG RecoveryInProgress : 1;
    ULONG Throttle : 1;
    ULONG Reserved : 23;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} WHEA_ERROR_RECORD_HEADER_FLAGS, *PWHEA_ERROR_RECORD_HEADER_FLAGS;