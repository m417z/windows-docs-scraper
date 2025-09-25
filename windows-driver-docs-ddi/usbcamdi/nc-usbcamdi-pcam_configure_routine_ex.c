PCAM_CONFIGURE_ROUTINE_EX PcamConfigureRoutineEx;

NTSTATUS PcamConfigureRoutineEx(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PUSBD_INTERFACE_INFORMATION Interface,
  PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
  ULONG PipeConfigListSize,
  PUSBCAMD_Pipe_Config_Descriptor PipeConfig,
  PUSB_DEVICE_DESCRIPTOR DeviceDescriptor
)
{...}