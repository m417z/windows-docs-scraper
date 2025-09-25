DXGKDDI_VIDPNSOURCEMODESET_GETNUMMODES DxgkddiVidpnsourcemodesetGetnummodes;

NTSTATUS DxgkddiVidpnsourcemodesetGetnummodes(
  [in]  IN_CONST_D3DKMDT_HVIDPNSOURCEMODESET hVidPnSourceModeSet,
  [out] OUT_PSIZE_T_CONST pNumSourceModes
)
{...}