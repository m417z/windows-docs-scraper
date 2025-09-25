typedef union _MCG_CAP {
  struct {
    ULONG64 CountField : 8;
    ULONG64 ControlMsrPresent : 1;
    ULONG64 ExtendedMsrsPresent : 1;
    ULONG64 SignalingExtensionPresent : 1;
    ULONG64 ThresholdErrorStatusPresent : 1;
    ULONG64 Reserved : 4;
    ULONG64 ExtendedRegisterCount : 8;
    ULONG64 SoftwareErrorRecoverySupported : 1;
    ULONG64 EnhancedMachineCheckCapability : 1;
    ULONG64 ExtendedErrorLogging : 1;
    ULONG64 LocalMachineCheckException : 1;
  } DUMMYSTRUCTNAME;
  ULONG64 QuadPart;
} MCG_CAP, *PMCG_CAP;