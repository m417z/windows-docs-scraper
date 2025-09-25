KSDDKAPI NTSTATUS KsMethodHandlerWithAllocator(
  [in]           PIRP               Irp,
  [in]           ULONG              MethodSetsCount,
  [in]           const KSMETHOD_SET *MethodSet,
  [in, optional] PFNKSALLOCATOR     Allocator,
  [in, optional] ULONG              MethodItemSize
);