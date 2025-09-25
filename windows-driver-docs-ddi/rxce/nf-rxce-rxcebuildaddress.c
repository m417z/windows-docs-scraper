NTSTATUS RxCeBuildAddress(
  [in, out] IN OUT PRXCE_ADDRESS           pAddress,
  [in]      IN PRXCE_TRANSPORT             pTransport,
  [in]      IN PTRANSPORT_ADDRESS          pTransportAddress,
  [in]      IN PRXCE_ADDRESS_EVENT_HANDLER pHandler,
  [in]      IN PVOID                       pEventContext
);