VIRTUAL_HW_FIND_ADAPTER VirtualHwFindAdapter;

ULONG VirtualHwFindAdapter(
  PVOID DeviceExtension,
  PVOID HwContext,
  PVOID BusInformation,
  PVOID LowerDevice,
  PCHAR ArgumentString,
  PPORT_CONFIGURATION_INFORMATION ConfigInfo,
  PBOOLEAN Again
)
{...}