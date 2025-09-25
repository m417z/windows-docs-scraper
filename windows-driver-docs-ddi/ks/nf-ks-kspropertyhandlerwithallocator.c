KSDDKAPI NTSTATUS KsPropertyHandlerWithAllocator(
  [in]           PIRP                 Irp,
  [in]           ULONG                PropertySetsCount,
  [in]           const KSPROPERTY_SET *PropertySet,
  [in, optional] PFNKSALLOCATOR       Allocator,
  [in, optional] ULONG                PropertyItemSize
);