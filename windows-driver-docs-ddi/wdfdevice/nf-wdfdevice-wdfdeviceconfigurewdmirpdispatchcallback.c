NTSTATUS WdfDeviceConfigureWdmIrpDispatchCallback(
  [in]           WDFDEVICE                      Device,
  [in, optional] WDFDRIVER                      Driver,
  [in]           UCHAR                          MajorFunction,
                 PFN_WDFDEVICE_WDM_IRP_DISPATCH EvtDeviceWdmIrpDispatch,
  [in, optional] WDFCONTEXT                     DriverContext
);