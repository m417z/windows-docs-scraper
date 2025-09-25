NTSTATUS FLTAPI FltGetVolumeGuidName(
  [in]               PFLT_VOLUME     Volume,
  [in/out, optional] PUNICODE_STRING VolumeGuidName,
  [out, optional]    PULONG          BufferSizeNeeded
);