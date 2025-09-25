NTSTATUS FLTAPI FltFlushBuffers2(
  PFLT_INSTANCE      Instance,
  PFILE_OBJECT       FileObject,
  ULONG              FlushType,
  PFLT_CALLBACK_DATA CallbackData
);