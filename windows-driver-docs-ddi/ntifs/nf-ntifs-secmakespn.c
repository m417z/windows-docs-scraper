KSECDDDECLSPEC NTSTATUS SecMakeSPN(
  [in]            IN PUNICODE_STRING     ServiceClass,
  [in]            IN PUNICODE_STRING     ServiceName,
  [in, optional]  IN PUNICODE_STRING     InstanceName,
  [in, optional]  IN USHORT              InstancePort,
  [in, optional]  IN PUNICODE_STRING     Referrer,
  [in, out]       IN OUT PUNICODE_STRING Spn,
  [out, optional] OUT PULONG             Length,
  [in]            IN BOOLEAN             Allocate
);