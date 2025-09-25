NTSTATUS __RxSynchronizeBlockingOperations(
  [in, out] IN OUT PRX_CONTEXT RxContext,
  [in]      IN PFCB            Fcb,
  [in, out] IN OUT PLIST_ENTRY BlockingIoQ,
  [in]      IN BOOLEAN         DropFcbLock
);