KSDDKAPI NTSTATUS KsPinGetConnectedFilterInterface(
  [in]  PKSPIN     Pin,
  [in]  const GUID *InterfaceId,
  [out] PVOID      *Interface
);