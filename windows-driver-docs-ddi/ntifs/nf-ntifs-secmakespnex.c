KSECDDDECLSPEC NTSTATUS SecMakeSPNEx(
  [in]            IN PUNICODE_STRING     ServiceClass,
  [in]            IN PUNICODE_STRING     ServiceName,
  [in]            IN PUNICODE_STRING     InstanceName,
  [in, optional]  IN USHORT              InstancePort,
  [in, optional]  IN PUNICODE_STRING     Referrer,
  [in, optional]  IN PUNICODE_STRING     TargetInfo,
  [in, out]       IN OUT PUNICODE_STRING Spn,
  [out, optional] OUT PULONG             Length,
  [in]            IN BOOLEAN             Allocate
);