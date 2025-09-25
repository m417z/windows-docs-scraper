SRIOV_GET_VENDOR_AND_DEVICE_IDS SriovGetVendorAndDeviceIds;

VOID SriovGetVendorAndDeviceIds(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [out] PUSHORT VendorId,
  [out] PUSHORT DeviceId
)
{...}