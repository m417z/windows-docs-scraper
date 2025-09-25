DXGKDDI_DESCRIBEALLOCATION DxgkddiDescribeallocation;

NTSTATUS DxgkddiDescribeallocation(
  [in]     IN_CONST_HANDLE hAdapter,
  [in/out] INOUT_PDXGKARG_DESCRIBEALLOCATION pDescribeAllocation
)
{...}