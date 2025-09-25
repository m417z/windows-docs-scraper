HRESULT RoInspectThreadErrorInfo(
  [in]           UINT_PTR                 targetTebAddress,
                 USHORT                   machine,
                 PINSPECT_MEMORY_CALLBACK readMemoryCallback,
  [in, optional] PVOID                    context,
  [out]          UINT_PTR                 *targetErrorInfoAddress
);