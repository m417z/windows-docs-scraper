NTSYSAPI LOGICAL RtlFreeHeap(
  [in]           PVOID                 HeapHandle,
  [in, optional] ULONG                 Flags,
                 _Frees_ptr_opt_ PVOID BaseAddress
);