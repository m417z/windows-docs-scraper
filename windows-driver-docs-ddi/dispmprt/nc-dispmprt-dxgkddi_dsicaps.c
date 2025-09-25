DXGKDDI_DSICAPS DxgkddiDsicaps;

NTSTATUS DxgkddiDsicaps(
  [in]  HANDLE Context,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
  [out] PDXGK_DSI_CAPS pArgs
)
{...}