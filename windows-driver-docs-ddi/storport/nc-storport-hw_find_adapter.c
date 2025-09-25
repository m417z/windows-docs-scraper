HW_FIND_ADAPTER HwFindAdapter;

ULONG HwFindAdapter(
           PVOID DeviceExtension,
  [in]     PVOID HwContext,
  [in]     PVOID BusInformation,
  [in]     PCHAR ArgumentString,
  [in/out] PPORT_CONFIGURATION_INFORMATION ConfigInfo,
  [in]     PBOOLEAN Reserved3
)
{...}