DXGKDDI_DSITRANSMISSION DxgkddiDsitransmission;

NTSTATUS DxgkddiDsitransmission(
  [in]  HANDLE Context,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
  [out] PDXGK_DSI_TRANSMISSION pArgs
)
{...}