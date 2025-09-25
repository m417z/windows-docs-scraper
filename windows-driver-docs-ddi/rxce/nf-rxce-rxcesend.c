NTSTATUS RxCeSend(
  [in] IN PRXCE_VC pVc,
  [in] IN ULONG    SendOptions,
  [in] IN PMDL     pMdl,
  [in] IN ULONG    SendLength,
  [in] IN PVOID    pCompletionContext
);