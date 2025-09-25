NTSTATUS FLTAPI FltRetrieveIoPriorityInfo(
  [in, optional] PFLT_CALLBACK_DATA Data,
  [in, optional] PFILE_OBJECT       FileObject,
  [in, optional] PETHREAD           Thread,
  [in, out]      PIO_PRIORITY_INFO  PriorityInfo
);