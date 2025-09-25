DXGKDDI_DSIRESET DxgkddiDsireset;

NTSTATUS DxgkddiDsireset(
  [in]  HANDLE Context,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
  [out] PDXGK_DSI_RESET pArgs
)
{...}