NTSTATUS FLTAPI FltDeleteVolumeContext(
  [in]            PFLT_FILTER  Filter,
  [in]            PFLT_VOLUME  Volume,
  [out, optional] PFLT_CONTEXT *OldContext
);