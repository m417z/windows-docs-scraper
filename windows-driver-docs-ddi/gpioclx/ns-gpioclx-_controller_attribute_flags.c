typedef union _CONTROLLER_ATTRIBUTE_FLAGS {
  struct {
    ULONG MemoryMappedController : 1;
    ULONG ActiveInterruptsAutoClearOnRead : 1;
    ULONG FormatIoRequestsAsMasks : 1;
    ULONG DeviceIdlePowerMgmtSupported : 1;
    ULONG BankIdlePowerMgmtSupported : 1;
    ULONG EmulateDebouncing : 1;
    ULONG EmulateActiveBoth : 1;
    ULONG IndependentIoHwSupported : 1;
    ULONG Reserved : 24;
  };
  ULONG  AsULONG;
} CONTROLLER_ATTRIBUTE_FLAGS, *PCONTROLLER_ATTRIBUTE_FLAGS;