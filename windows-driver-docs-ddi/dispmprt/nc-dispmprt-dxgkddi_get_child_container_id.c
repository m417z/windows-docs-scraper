DXGKDDI_GET_CHILD_CONTAINER_ID DxgkddiGetChildContainerId;

NTSTATUS DxgkddiGetChildContainerId(
  [in]      PVOID MiniportDeviceContext,
  [in]      ULONG ChildUid,
  [in, out] PDXGK_CHILD_CONTAINER_ID ContainerId
)
{...}