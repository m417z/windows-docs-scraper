PAGP_RESERVE_VIRTUAL PagpReserveVirtual;

PVOID PagpReserveVirtual(
  [in]  IN PVOID HwDeviceExtension,
  [in]  IN HANDLE ProcessHandle,
  [in]  IN PVOID PhysicalReserveContext,
  [out] OUT PVOID *VirtualReserveContext
)
{...}