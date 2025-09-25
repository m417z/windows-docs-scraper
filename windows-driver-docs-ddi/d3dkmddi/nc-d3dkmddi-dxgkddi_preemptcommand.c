DXGKDDI_PREEMPTCOMMAND DxgkddiPreemptcommand;

NTSTATUS DxgkddiPreemptcommand(
  [in] IN_CONST_HANDLE hAdapter,
  [in] IN_CONST_PDXGKARG_PREEMPTCOMMAND pPreemptCommand
)
{...}