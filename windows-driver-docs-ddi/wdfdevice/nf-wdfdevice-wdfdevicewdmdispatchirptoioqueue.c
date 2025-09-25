NTSTATUS WdfDeviceWdmDispatchIrpToIoQueue(
  [in] WDFDEVICE Device,
  [in] PIRP      Irp,
  [in] WDFQUEUE  Queue,
  [in] ULONG     Flags
);