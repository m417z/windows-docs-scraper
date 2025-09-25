DXGKDDI_QUERYCURRENTFENCE DxgkddiQuerycurrentfence;

NTSTATUS DxgkddiQuerycurrentfence(
  [in]     IN_CONST_HANDLE hAdapter,
  [in/out] INOUT_PDXGKARG_QUERYCURRENTFENCE pCurrentFence
)
{...}