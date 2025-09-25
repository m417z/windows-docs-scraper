NTSTATUS FLTAPI FltWriteFileEx(
  [in]            PFLT_INSTANCE                    InitiatingInstance,
  [in]            PFILE_OBJECT                     FileObject,
  [in, optional]  PLARGE_INTEGER                   ByteOffset,
  [in]            ULONG                            Length,
  [in]            PVOID                            Buffer,
  [in]            FLT_IO_OPERATION_FLAGS           Flags,
  [out, optional] PULONG                           BytesWritten,
  [in, optional]  PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
  [in, optional]  PVOID                            CallbackContext,
  [in, optional]  PULONG                           Key,
  [in, optional]  PMDL                             Mdl
);