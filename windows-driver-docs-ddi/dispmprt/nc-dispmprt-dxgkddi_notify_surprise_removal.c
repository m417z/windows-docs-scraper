DXGKDDI_NOTIFY_SURPRISE_REMOVAL DxgkddiNotifySurpriseRemoval;

NTSTATUS DxgkddiNotifySurpriseRemoval(
  [in] PVOID MiniportDeviceContext,
  [in] DXGK_SURPRISE_REMOVAL_TYPE RemovalType
)
{...}