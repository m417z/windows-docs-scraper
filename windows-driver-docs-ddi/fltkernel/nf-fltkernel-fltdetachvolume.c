NTSTATUS FLTAPI FltDetachVolume(
  [in, out]      PFLT_FILTER      Filter,
  [in, out]      PFLT_VOLUME      Volume,
  [in, optional] PCUNICODE_STRING InstanceName
);