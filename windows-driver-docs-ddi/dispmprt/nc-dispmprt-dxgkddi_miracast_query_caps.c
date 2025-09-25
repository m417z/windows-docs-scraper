DXGKDDI_MIRACAST_QUERY_CAPS DxgkddiMiracastQueryCaps;

NTSTATUS DxgkddiMiracastQueryCaps(
  [in]  PVOID DriverContext,
  [in]  ULONG MiracastCapsSize,
  [out] DXGK_MIRACAST_CAPS *MiracastCaps
)
{...}