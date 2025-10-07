NTSTATUS __RxSynchronizeBlockingOperationsMaybeDroppingFcbLock(
  _Inout_ PRX_CONTEXT RxContext,
  _Inout_ PLIST_ENTRY BlockingIoQ,
  _In_    BOOLEAN     DropFcbLock
);