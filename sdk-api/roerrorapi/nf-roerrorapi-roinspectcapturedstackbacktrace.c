HRESULT RoInspectCapturedStackBackTrace(
  [in]           UINT_PTR                 targetErrorInfoAddress,
                 USHORT                   machine,
                 PINSPECT_MEMORY_CALLBACK readMemoryCallback,
  [in, optional] PVOID                    context,
  [out]          UINT32                   *frameCount,
  [out]          UINT_PTR                 *targetBackTraceAddress
);