HRESULT WriteBytes(
  IDebugHostContext *context,
  Location          location,
  void              *buffer,
  ULONG64           bufferSize,
  ULONG64           *bytesWritten
);