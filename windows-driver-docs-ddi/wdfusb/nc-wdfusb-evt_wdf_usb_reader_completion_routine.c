EVT_WDF_USB_READER_COMPLETION_ROUTINE EvtWdfUsbReaderCompletionRoutine;

VOID EvtWdfUsbReaderCompletionRoutine(
  [in] WDFUSBPIPE Pipe,
  [in] WDFMEMORY Buffer,
  [in] size_t NumBytesTransferred,
  [in] WDFCONTEXT Context
)
{...}