BOOLEAN NdisMSynchronizeWithInterruptEx(
  [in] NDIS_HANDLE                            NdisInterruptHandle,
  [in] ULONG                                  MessageId,
  [in] MINIPORT_SYNCHRONIZE_INTERRUPT_HANDLER SynchronizeFunction,
  [in] PVOID                                  SynchronizeFunction,
  [in] PVOID                                  SynchronizeContext
);