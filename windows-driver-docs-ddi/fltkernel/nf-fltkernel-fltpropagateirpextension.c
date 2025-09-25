NTSTATUS FLTAPI FltPropagateIrpExtension(
  [in]     PFLT_CALLBACK_DATA SourceData,
  [in/out] PFLT_CALLBACK_DATA TargetData,
  [in]     ULONG              Flags
);