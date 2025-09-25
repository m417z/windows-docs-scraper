BOOL GetEnlistmentRecoveryInformation(
  [in]            HANDLE EnlistmentHandle,
  [in]            ULONG  BufferSize,
  [out]           PVOID  Buffer,
  [out, optional] PULONG BufferUsed
);