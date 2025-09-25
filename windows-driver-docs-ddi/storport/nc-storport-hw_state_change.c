HW_STATE_CHANGE HwStateChange;

VOID HwStateChange(
                 PVOID HwDeviceExtension,
  [in, optional] PVOID Context,
  [in]           SHORT AddressType,
  [in]           PVOID Address,
  [in]           ULONG Status
)
{...}