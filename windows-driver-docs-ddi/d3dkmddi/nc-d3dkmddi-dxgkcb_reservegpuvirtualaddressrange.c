DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE DxgkcbReservegpuvirtualaddressrange;

NTSTATUS DxgkcbReservegpuvirtualaddressrange(
  [in]     IN_CONST_HANDLE hAdapter,
  [in/out] INOUT_PDXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE pArgs
)
{...}