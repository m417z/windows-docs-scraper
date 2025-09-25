PINSPECT_MEMORY_CALLBACK PinspectMemoryCallback;

HRESULT PinspectMemoryCallback(
  [in]  void *context,
  [in]  UINT_PTR readAddress,
  [in]  UINT32 length,
  [out] BYTE *buffer
)
{...}