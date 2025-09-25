PVIDEO_HW_LEGACYRESOURCES PvideoHwLegacyresources;

VOID PvideoHwLegacyresources(
  [in]      IN ULONG VendorId,
  [in]      IN ULONG DeviceId,
  [in, out] IN OUT PVIDEO_ACCESS_RANGE *LegacyResourceList,
  [in, out] IN OUT PULONG LegacyResourceCount
)
{...}