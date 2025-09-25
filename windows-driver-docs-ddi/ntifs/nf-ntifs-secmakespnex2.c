KSECDDDECLSPEC NTSTATUS SecMakeSPNEx2(
  [in]            IN PUNICODE_STRING     ServiceClass,
  [in]            IN PUNICODE_STRING     ServiceName,
  [in, optional]  IN PUNICODE_STRING     InstanceName,
  [in, optional]  IN USHORT              InstancePort,
  [in, optional]  IN PUNICODE_STRING     Referrer,
  [in, optional]  IN PUNICODE_STRING     InTargetInfo,
  [in, out]       IN OUT PUNICODE_STRING Spn,
  [out, optional] OUT PULONG             TotalSize,
  [in]            IN BOOLEAN             Allocate,
  [in]            IN BOOLEAN             IsTargetInfoMarshaled
);