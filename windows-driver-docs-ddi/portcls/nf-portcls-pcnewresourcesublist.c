PORTCLASSAPI NTSTATUS PcNewResourceSublist(
  [out]          PRESOURCELIST *OutResourceList,
  [in, optional] PUNKNOWN      OuterUnknown,
  [in]           POOL_TYPE     PoolType,
  [in]           PRESOURCELIST ParentList,
  [in]           ULONG         MaximumEntries
);