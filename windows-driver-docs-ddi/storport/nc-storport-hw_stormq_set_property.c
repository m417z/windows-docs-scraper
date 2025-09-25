HW_STORMQ_SET_PROPERTY HwStormqSetProperty;

ULONG HwStormqSetProperty(
  PVOID ControllerExtension,
  ULONG NvmePropertyOffset,
  ULONG PropertyLength,
  ULONG Flags,
  PVOID PropertyBuffer
)
{...}