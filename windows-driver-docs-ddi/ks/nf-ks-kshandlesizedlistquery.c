KSDDKAPI NTSTATUS KsHandleSizedListQuery(
  [in] PIRP       Irp,
  [in] ULONG      DataItemsCount,
  [in] ULONG      DataItemSize,
  [in] const VOID *DataItems
);