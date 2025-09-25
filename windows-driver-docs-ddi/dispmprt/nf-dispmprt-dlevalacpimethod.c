NTSTATUS DlEvalAcpiMethod(
  HANDLE                          DeviceHandle,
  ULONG                           DeviceUid,
  PACPI_EVAL_INPUT_BUFFER_COMPLEX AcpiInputBuffer,
  ULONG                           AcpiInputSize,
  PACPI_EVAL_OUTPUT_BUFFER        AcpiOutputBuffer,
  ULONG                           AcpiOutputSize
);