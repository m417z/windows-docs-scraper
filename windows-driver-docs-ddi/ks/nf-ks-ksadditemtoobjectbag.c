KSDDKAPI NTSTATUS KsAddItemToObjectBag(
  [in]           KSOBJECT_BAG           ObjectBag,
  [in]           __drv_aliasesMem PVOID Item,
  [in, optional] PFNKSFREE              Free
);