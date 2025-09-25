KSDDKAPI NTSTATUS KsPinGetConnectedPinInterface(
  [in]  PKSPIN     Pin,
  [in]  const GUID *InterfaceId,
  [out] PVOID      *Interface
);