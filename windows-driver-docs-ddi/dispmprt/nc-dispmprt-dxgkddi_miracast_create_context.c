DXGKDDI_MIRACAST_CREATE_CONTEXT DxgkddiMiracastCreateContext;

NTSTATUS DxgkddiMiracastCreateContext(
  [in]  PVOID DriverContext,
  [in]  DXGK_MIRACAST_DISPLAY_CALLBACKS *MiracastCallbacks,
  [out] PVOID *MiracastContext,
  [out] ULONG *TargetId
)
{...}