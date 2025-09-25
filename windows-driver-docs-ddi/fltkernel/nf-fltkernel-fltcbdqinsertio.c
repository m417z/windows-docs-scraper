NTSTATUS FLTAPI FltCbdqInsertIo(
  [in, out]      PFLT_CALLBACK_DATA_QUEUE            Cbdq,
  [in]           PFLT_CALLBACK_DATA                  Cbd,
  [in, optional] PFLT_CALLBACK_DATA_QUEUE_IO_CONTEXT Context,
  [in, optional] PVOID                               InsertContext
);