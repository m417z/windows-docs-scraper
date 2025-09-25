KSDDKAPI NTSTATUS KsFilterCreatePinFactory(
  [in]  PKSFILTER                         Filter,
  [in]  const KSPIN_DESCRIPTOR_EX * const PinDescriptor,
  [out] PULONG                            PinID
);