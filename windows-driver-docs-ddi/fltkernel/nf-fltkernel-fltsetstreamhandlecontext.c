NTSTATUS FLTAPI FltSetStreamHandleContext(
  [in]            PFLT_INSTANCE             Instance,
  [in]            PFILE_OBJECT              FileObject,
  [in]            FLT_SET_CONTEXT_OPERATION Operation,
  [in]            PFLT_CONTEXT              NewContext,
  [out, optional] PFLT_CONTEXT              *OldContext
);