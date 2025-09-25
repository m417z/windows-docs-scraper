KSDDKAPI NTSTATUS _KsEdit(
  [in]      KSOBJECT_BAG ObjectBag,
  [in, out] PVOID        *PointerToPointerToItem,
  [in]      ULONG        NewSize,
  [in]      ULONG        OldSize,
  [in]      ULONG        Tag
);