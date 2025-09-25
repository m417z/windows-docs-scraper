typedef union _WHEA_ERROR_PACKET_FLAGS {
  struct {
    ULONG PreviousError : 1;
    ULONG CriticalEvent : 1;
    ULONG HypervisorError : 1;
    ULONG Simulated : 1;
    ULONG PlatformPfaControl : 1;
    ULONG PlatformDirectedOffline : 1;
    ULONG AddressTranslationRequired : 1;
    ULONG AddressTranslationCompleted : 1;
    ULONG RecoveryOptional : 1;
    ULONG Reserved2 : 23;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} WHEA_ERROR_PACKET_FLAGS, *PWHEA_ERROR_PACKET_FLAGS;