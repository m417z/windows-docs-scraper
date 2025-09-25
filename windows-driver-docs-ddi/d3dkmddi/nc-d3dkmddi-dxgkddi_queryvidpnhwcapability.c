DXGKDDI_QUERYVIDPNHWCAPABILITY DxgkddiQueryvidpnhwcapability;

NTSTATUS DxgkddiQueryvidpnhwcapability(
  [in]     IN_CONST_HANDLE i_hAdapter,
  [in/out] INOUT_PDXGKARG_QUERYVIDPNHWCAPABILITY io_pVidPnHWCaps
)
{...}