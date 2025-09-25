PHW_FIND_ADAPTER PhwFindAdapter;

ULONG PhwFindAdapter(
  [in]      PVOID DeviceExtension,
  [in]      PVOID HwContext,
  [in]      PVOID BusInformation,
  [in]      PCHAR ArgumentString,
  [in, out] PPORT_CONFIGURATION_INFORMATION ConfigInfo,
  [out]     PBOOLEAN Again
)
{...}