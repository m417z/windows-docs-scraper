NTSTATUS FLTAPI FltGetVolumeName(
  [in]                PFLT_VOLUME     Volume,
  [in, out, optional] PUNICODE_STRING VolumeName,
  [out, optional]     PULONG          BufferSizeNeeded
);