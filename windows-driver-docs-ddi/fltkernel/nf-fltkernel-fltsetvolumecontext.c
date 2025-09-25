NTSTATUS FLTAPI FltSetVolumeContext(
  [in]            PFLT_VOLUME               Volume,
  [in]            FLT_SET_CONTEXT_OPERATION Operation,
  [in]            PFLT_CONTEXT              NewContext,
  [out, optional] PFLT_CONTEXT              *OldContext
);