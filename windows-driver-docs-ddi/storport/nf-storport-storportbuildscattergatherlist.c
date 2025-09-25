ULONG StorPortBuildScatterGatherList(
  [in]      PVOID                        HwDeviceExtension,
  [in]      PVOID                        Mdl,
  [in]      PVOID                        CurrentVa,
  [in]      ULONG                        Length,
  [in]      PPOST_SCATTER_GATHER_EXECUTE ExecutionRoutine,
  [in]      PVOID                        Context,
  [in]      BOOLEAN                      WriteToDevice,
  [in, out] PVOID                        ScatterGatherBuffer,
  [in]      ULONG                        ScatterGatherBufferLength
);