NTSTATUS FLTAPI FltAllocateCallbackData(
  [in]           PFLT_INSTANCE      Instance,
  [in, optional] PFILE_OBJECT       FileObject,
  [out]          PFLT_CALLBACK_DATA *RetNewCallbackData
);