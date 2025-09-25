KSDDKAPI NTSTATUS KsAllocateObjectCreateItem(
  [in]           KSDEVICE_HEADER       Header,
  [in]           PKSOBJECT_CREATE_ITEM CreateItem,
  [in]           BOOLEAN               AllocateEntry,
  [in, optional] PFNKSITEMFREECALLBACK ItemFreeCallback
);