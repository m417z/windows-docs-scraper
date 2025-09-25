NTSTATUS RxCeBuildConnection(
            IN PRXCE_ADDRESS                  pLocalAddress,
  [in]      IN PRXCE_CONNECTION_INFORMATION   pConnectionInformation,
  [in]      IN PRXCE_CONNECTION_EVENT_HANDLER pHandler,
  [in]      IN PVOID                          pEventContext,
  [in, out] IN OUT PRXCE_CONNECTION           pConnection,
  [in, out] IN OUT PRXCE_VC                   pVc
);