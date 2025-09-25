VIDEOPORT_DEPRECATED VIDEOPORT_API PVOID VideoPortGetCommonBuffer(
  [in]  IN PVOID              HwDeviceExtension,
  [in]  IN ULONG              DesiredLength,
  [in]  IN ULONG              Alignment,
  [out] OUT PPHYSICAL_ADDRESS LogicalAddress,
  [out] OUT PULONG            pActualLength,
  [in]  IN BOOLEAN            CacheEnabled
);