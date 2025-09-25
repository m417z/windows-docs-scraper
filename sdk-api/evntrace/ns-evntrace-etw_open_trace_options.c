typedef struct ETW_OPEN_TRACE_OPTIONS {
  ETW_PROCESS_TRACE_MODES ProcessTraceModes;
  PEVENT_RECORD_CALLBACK  EventCallback;
  void                    *EventCallbackContext;
  PETW_BUFFER_CALLBACK    BufferCallback;
  void                    *BufferCallbackContext;
} ETW_OPEN_TRACE_OPTIONS;