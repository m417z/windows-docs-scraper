PETW_BUFFER_CALLBACK PetwBufferCallback;

BOOL PetwBufferCallback(
  const ETW_BUFFER_HEADER *Buffer,
  ULONG BufferSize,
  const ETW_BUFFER_CALLBACK_INFORMATION *ConsumerInfo,
  void *CallbackContext
)
{...}