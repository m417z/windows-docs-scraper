KSDDKAPI NTSTATUS KsPinPropertyHandler(
  [in]      PIRP                   Irp,
  [in]      PKSPROPERTY            Property,
  [in, out] PVOID                  Data,
  [in]      ULONG                  DescriptorsCount,
  [in]      const KSPIN_DESCRIPTOR *Descriptor
);