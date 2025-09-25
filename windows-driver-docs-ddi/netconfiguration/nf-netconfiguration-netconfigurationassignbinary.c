NTSTATUS NetConfigurationAssignBinary(
  [_In_]                             NETCONFIGURATION Configuration,
  [_In_]                             PCUNICODE_STRING ValueName,
  [__In_reads_bytes_(BufferLength)_] void             *Buffer,
  [_In_]                             ULONG            BufferLength
);