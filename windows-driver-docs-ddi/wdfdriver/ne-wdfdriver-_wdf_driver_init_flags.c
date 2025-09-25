typedef enum _WDF_DRIVER_INIT_FLAGS {
  WdfDriverInitNonPnpDriver = 0x00000001,
  WdfDriverInitNoDispatchOverride = 0x00000002,
  WdfVerifyOn = 0x00000004,
  WdfVerifierOn = 0x00000008,
  WdfDriverInitCompanion = 0x00000010
} WDF_DRIVER_INIT_FLAGS;