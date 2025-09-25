DXGKDDI_OPM_CREATE_PROTECTED_OUTPUT_NONLOCAL_DISPLAY DxgkddiOpmCreateProtectedOutputNonlocalDisplay;

NTSTATUS DxgkddiOpmCreateProtectedOutputNonlocalDisplay(
  PVOID MiniportDeviceContext,
  DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS NewVideoOutputSemantics,
  UINT64 OPMEncoderContext,
  DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT *pActualOutputFormat,
  UINT64 NonLocalOutputId,
  DXGKMDT_OPM_CONNECTOR_TYPE NonLocalConnectorType,
  PHANDLE NewProtectedOutputHandle
)
{...}