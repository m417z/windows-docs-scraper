NTSYSAPI NTSTATUS RtlGetPersistedStateLocation(
  [_In_]      PCWSTR              SourceID,
  [_In_opt_]  PCWSTR              CustomValue,
  [_In_opt_]  PCWSTR              DefaultPath,
  [_In_]      STATE_LOCATION_TYPE StateLocationType,
  [_In_]      PWCHAR              TargetPath,
  [_In_]      ULONG               BufferLengthIn,
  [_Out_opt_] PULONG              BufferLengthOut
);