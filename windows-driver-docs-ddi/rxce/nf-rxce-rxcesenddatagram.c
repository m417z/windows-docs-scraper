NTSTATUS RxCeSendDatagram(
       IN PRXCE_ADDRESS                hAddress,
  [in] IN PRXCE_CONNECTION_INFORMATION pConnectionInformation,
       IN ULONG                        SendOptions,
  [in] IN PMDL                         pMdl,
  [in] IN ULONG                        SendLength,
  [in] IN PVOID                        pCompletionContext
);