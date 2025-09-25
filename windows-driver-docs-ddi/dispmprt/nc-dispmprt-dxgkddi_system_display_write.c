DXGKDDI_SYSTEM_DISPLAY_WRITE DxgkddiSystemDisplayWrite;

VOID DxgkddiSystemDisplayWrite(
  [in] PVOID MiniportDeviceContext,
  [in] PVOID Source,
  [in] UINT SourceWidth,
  [in] UINT SourceHeight,
  [in] UINT SourceStride,
  [in] UINT PositionX,
  [in] UINT PositionY
)
{...}