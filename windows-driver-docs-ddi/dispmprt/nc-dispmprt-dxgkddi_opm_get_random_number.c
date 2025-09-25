DXGKDDI_OPM_GET_RANDOM_NUMBER DxgkddiOpmGetRandomNumber;

NTSTATUS DxgkddiOpmGetRandomNumber(
  [in]  PVOID MiniportDeviceContext,
  [in]  HANDLE ProtectedOutputHandle,
  [out] PDXGKMDT_OPM_RANDOM_NUMBER RandomNumber
)
{...}