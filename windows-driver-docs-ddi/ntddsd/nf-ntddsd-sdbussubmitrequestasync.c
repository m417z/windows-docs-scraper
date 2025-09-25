NTSTATUS SdBusSubmitRequestAsync(
  [in] PVOID                  InterfaceContext,
  [in] PSDBUS_REQUEST_PACKET  Packet,
  [in] PIRP                   Irp,
  [in] PIO_COMPLETION_ROUTINE CompletionRoutine,
  [in] PVOID                  UserContext
);