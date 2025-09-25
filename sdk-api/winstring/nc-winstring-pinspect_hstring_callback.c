PINSPECT_HSTRING_CALLBACK PinspectHstringCallback;

HRESULT PinspectHstringCallback(
  void *context,
  UINT_PTR readAddress,
  UINT32 length,
  BYTE *buffer
)
{...}