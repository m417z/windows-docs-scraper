DXGKCB_INDICATE_CHILD_STATUS DxgkcbIndicateChildStatus;

NTSTATUS DxgkcbIndicateChildStatus(
  [in] HANDLE DeviceHandle,
  [in] PDXGK_CHILD_STATUS ChildStatus
)
{...}