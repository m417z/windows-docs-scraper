DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA DxgkddiGetstandardallocationdriverdata;

NTSTATUS DxgkddiGetstandardallocationdriverdata(
  [in]     IN_CONST_HANDLE hAdapter,
  [in/out] INOUT_PDXGKARG_GETSTANDARDALLOCATIONDRIVERDATA pGetStandardAllocationDriverData
)
{...}