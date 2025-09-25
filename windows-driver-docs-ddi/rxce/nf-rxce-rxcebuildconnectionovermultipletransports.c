NTSTATUS RxCeBuildConnectionOverMultipleTransports(
  [in, out] IN OUT PRDBSS_DEVICE_OBJECT                pMiniRedirectorDeviceObject,
            IN RXCE_CONNECTION_CREATE_OPTIONS          CreateOption,
  [in]      IN ULONG                                   NumberOfAddresses,
  [in]      IN PRXCE_ADDRESS                           *pLocalAddressPointers,
  [in]      IN PUNICODE_STRING                         pServerName,
  [in]      IN PRXCE_CONNECTION_INFORMATION            pConnectionInformation,
  [in]      IN PRXCE_CONNECTION_EVENT_HANDLER          pHandler,
  [in]      IN PVOID                                   pEventContext,
  [in]      IN PRXCE_CONNECTION_COMPLETION_ROUTINE     pCompletionRoutine,
  [in, out] IN OUT PRXCE_CONNECTION_COMPLETION_CONTEXT pCompletionContext
);