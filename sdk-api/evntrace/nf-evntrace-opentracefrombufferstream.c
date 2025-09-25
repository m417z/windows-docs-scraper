ETW_APP_DECLSPEC_DEPRECATED PROCESSTRACE_HANDLE WMIAPI OpenTraceFromBufferStream(
  const ETW_OPEN_TRACE_OPTIONS    *Options,
  PETW_BUFFER_COMPLETION_CALLBACK BufferCompletionCallback,
  void                            *BufferCompletionContext
);