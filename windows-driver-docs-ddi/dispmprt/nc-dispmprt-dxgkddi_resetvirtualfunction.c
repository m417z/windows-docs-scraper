DXGKDDI_RESETVIRTUALFUNCTION DxgkddiResetvirtualfunction;

NTSTATUS DxgkddiResetvirtualfunction(
  [in]      HANDLE Context,
  [in, out] DXGKARG_RESETVIRTUALFUNCTION *pArgs
)
{...}