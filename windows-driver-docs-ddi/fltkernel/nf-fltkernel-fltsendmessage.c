NTSTATUS FLTAPI FltSendMessage(
  [in]            PFLT_FILTER    Filter,
  [in]            PFLT_PORT      *ClientPort,
  [in]            PVOID          SenderBuffer,
  [in]            ULONG          SenderBufferLength,
  [out, optional] PVOID          ReplyBuffer,
  [in, out]       PULONG         ReplyLength,
  [in, optional]  PLARGE_INTEGER Timeout
);