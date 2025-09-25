HW_STORMQ_QUERY_PROPERTY HwStormqQueryProperty;

ULONG HwStormqQueryProperty(
  PVOID ControllerExtension,
  ULONG NvmePropertyOffset,
  ULONG PropertyLength,
  ULONG Flags,
  PVOID PropertyBuffer
)
{...}