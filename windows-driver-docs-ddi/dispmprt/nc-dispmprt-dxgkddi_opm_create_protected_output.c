DXGKDDI_OPM_CREATE_PROTECTED_OUTPUT DxgkddiOpmCreateProtectedOutput;

NTSTATUS DxgkddiOpmCreateProtectedOutput(
  [in]  PVOID MiniportDeviceContext,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId,
  [in]  DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS NewVideoOutputSemantics,
  [out] PHANDLE NewProtectedOutputHandle
)
{...}