VOID SpbControllerSetIoOtherCallback(
  [in]           WDFDEVICE                    FxDevice,
  [in]           PFN_SPB_CONTROLLER_OTHER     EvtSpbControllerIoOther,
  [in, optional] PFN_WDF_IO_IN_CALLER_CONTEXT EvtIoInCallerContext
);