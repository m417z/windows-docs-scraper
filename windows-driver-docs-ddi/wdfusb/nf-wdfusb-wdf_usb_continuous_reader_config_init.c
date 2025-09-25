VOID WDF_USB_CONTINUOUS_READER_CONFIG_INIT(
  [out] PWDF_USB_CONTINUOUS_READER_CONFIG     Config,
  [in]  PFN_WDF_USB_READER_COMPLETION_ROUTINE EvtUsbTargetPipeReadComplete,
  [in]  WDFCONTEXT                            EvtUsbTargetPipeReadCompleteContext,
  [in]  size_t                                TransferLength
);