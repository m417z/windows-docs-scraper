NTSTATUS FLTAPI FltAllocateCallbackDataEx(
  [in]          PFLT_INSTANCE                    Instance,
  [in/optional] PFILE_OBJECT                     FileObject,
  [in]          FLT_ALLOCATE_CALLBACK_DATA_FLAGS Flags,
  [out]         PFLT_CALLBACK_DATA               *RetNewCallbackData
);