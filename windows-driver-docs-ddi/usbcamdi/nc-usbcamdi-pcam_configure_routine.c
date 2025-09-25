PCAM_CONFIGURE_ROUTINE PcamConfigureRoutine;

NTSTATUS PcamConfigureRoutine(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PUSBD_INTERFACE_INFORMATION Interface,
  PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
  PLONG DataPipeIndex,
  PLONG SyncPipeIndex
)
{...}