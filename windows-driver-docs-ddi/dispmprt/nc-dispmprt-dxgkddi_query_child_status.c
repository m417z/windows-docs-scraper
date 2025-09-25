DXGKDDI_QUERY_CHILD_STATUS DxgkddiQueryChildStatus;

NTSTATUS DxgkddiQueryChildStatus(
  [in]      IN_CONST_PVOID MiniportDeviceContext,
  [in, out] INOUT_PDXGK_CHILD_STATUS ChildStatus,
  [in]      IN_BOOLEAN NonDestructiveOnly
)
{...}