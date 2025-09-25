__kernel_entry NTSTATUS NtQueryMultipleValueKey(
  [in]            HANDLE           KeyHandle,
  [in, out]       PKEY_VALUE_ENTRY ValueEntries,
  [in]            ULONG            EntryCount,
  [out]           PVOID            ValueBuffer,
  [in, out]       PULONG           BufferLength,
  [out, optional] PULONG           RequiredBufferLength
);