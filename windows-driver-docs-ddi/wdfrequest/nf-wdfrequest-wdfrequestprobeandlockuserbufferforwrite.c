NTSTATUS WdfRequestProbeAndLockUserBufferForWrite(
  [in]  WDFREQUEST Request,
  [in]  PVOID      Buffer,
  [in]  size_t     Length,
  [out] WDFMEMORY  *MemoryObject
);