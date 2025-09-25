NTSTATUS FLTAPI FltGetVolumeFromName(
  [in]  PFLT_FILTER      Filter,
  [in]  PCUNICODE_STRING VolumeName,
  [out] PFLT_VOLUME      *RetVolume
);