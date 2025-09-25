KSDDKAPI NTSTATUS KsLoadResource(
  [in]            PVOID     ImageBase,
  [in]            POOL_TYPE PoolType,
  [in]            ULONG_PTR ResourceName,
  [in]            ULONG     ResourceType,
  [out]           PVOID     *Resource,
  [out, optional] PULONG    ResourceSize
);