NTSTATUS FLTAPI FltGetVolumeInstanceFromName(
  [in, optional] PFLT_FILTER      Filter,
  [in]           PFLT_VOLUME      Volume,
  [in, optional] PCUNICODE_STRING InstanceName,
  [out]          PFLT_INSTANCE    *RetInstance
);