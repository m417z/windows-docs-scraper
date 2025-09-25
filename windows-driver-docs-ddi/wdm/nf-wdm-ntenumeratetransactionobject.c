__kernel_entry NTSYSCALLAPI NTSTATUS NtEnumerateTransactionObject(
  [in, optional] HANDLE            RootObjectHandle,
  [in]           KTMOBJECT_TYPE    QueryType,
  [in, out]      PKTMOBJECT_CURSOR ObjectCursor,
  [in]           ULONG             ObjectCursorLength,
  [out]          PULONG            ReturnLength
);