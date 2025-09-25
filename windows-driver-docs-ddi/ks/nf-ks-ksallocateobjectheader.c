KSDDKAPI NTSTATUS KsAllocateObjectHeader(
  [out]          KSOBJECT_HEADER        *Header,
  [in]           ULONG                  ItemsCount,
  [in, optional] PKSOBJECT_CREATE_ITEM  ItemsList,
  [in]           PIRP                   Irp,
  [in]           const KSDISPATCH_TABLE *Table
);