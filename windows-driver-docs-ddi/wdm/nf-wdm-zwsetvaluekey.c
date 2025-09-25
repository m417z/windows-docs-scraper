NTSYSAPI NTSTATUS ZwSetValueKey(
  [in]           HANDLE          KeyHandle,
  [in]           PUNICODE_STRING ValueName,
  [in, optional] ULONG           TitleIndex,
  [in]           ULONG           Type,
  [in, optional] PVOID           Data,
  [in]           ULONG           DataSize
);