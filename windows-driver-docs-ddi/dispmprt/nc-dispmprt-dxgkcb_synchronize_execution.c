DXGKCB_SYNCHRONIZE_EXECUTION DxgkcbSynchronizeExecution;

NTSTATUS DxgkcbSynchronizeExecution(
  [in]  HANDLE DeviceHandle,
  [in]  PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,
  [in]  PVOID Context,
  [in]  ULONG MessageNumber,
  [out] PBOOLEAN ReturnValue
)
{...}