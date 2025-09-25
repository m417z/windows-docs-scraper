DXGKCB_EVAL_ACPI_METHOD DxgkcbEvalAcpiMethod;

NTSTATUS DxgkcbEvalAcpiMethod(
  [in]  HANDLE DeviceHandle,
  [in]  ULONG DeviceUid,
  [in]  PACPI_EVAL_INPUT_BUFFER_COMPLEX AcpiInputBuffer,
  [in]  ULONG AcpiInputSize,
  [out] PACPI_EVAL_OUTPUT_BUFFER AcpiOutputBuffer,
  [in]  ULONG AcpiOutputSize
)
{...}