PETW_BUFFER_COMPLETION_CALLBACK PetwBufferCompletionCallback;

VOID PetwBufferCompletionCallback(
  const ETW_BUFFER_HEADER *Buffer,
  void *CallbackContext
)
{...}