KSDDKAPI NTSTATUS KsValidateConnectRequest(
  [in]  PIRP                   Irp,
  [in]  ULONG                  DescriptorsCount,
  [in]  const KSPIN_DESCRIPTOR *Descriptor,
  [out] PKSPIN_CONNECT         *Connect
);