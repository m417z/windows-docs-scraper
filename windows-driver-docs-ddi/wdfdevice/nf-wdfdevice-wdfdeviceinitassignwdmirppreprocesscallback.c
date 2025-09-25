NTSTATUS WdfDeviceInitAssignWdmIrpPreprocessCallback(
  [in]           PWDFDEVICE_INIT                  DeviceInit,
  [in]           PFN_WDFDEVICE_WDM_IRP_PREPROCESS EvtDeviceWdmIrpPreprocess,
  [in]           UCHAR                            MajorFunction,
  [in, optional] PUCHAR                           MinorFunctions,
  [in]           ULONG                            NumMinorFunctions
);