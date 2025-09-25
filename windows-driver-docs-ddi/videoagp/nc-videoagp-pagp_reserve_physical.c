PAGP_RESERVE_PHYSICAL PagpReservePhysical;

PHYSICAL_ADDRESS PagpReservePhysical(
  [in]  IN PVOID HwDeviceExtension,
  [in]  IN ULONG Pages,
  [in]  IN VIDEO_PORT_CACHE_TYPE Caching,
  [out] OUT PVOID *PhysicalReserveContext
)
{...}