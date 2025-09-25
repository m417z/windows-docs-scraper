NTSTATUS FLTAPI FltAttachVolumeAtAltitude(
  [in, out]       PFLT_FILTER      Filter,
  [in, out]       PFLT_VOLUME      Volume,
  [in]            PCUNICODE_STRING Altitude,
  [in, optional]  PCUNICODE_STRING InstanceName,
  [out, optional] PFLT_INSTANCE    *RetInstance
);