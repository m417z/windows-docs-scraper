PVOID ExAllocatePoolWithTagPriority(
  [in] __drv_strictTypeMatch(__drv_typeCond)POOL_TYPE        PoolType,
  [in] SIZE_T                                                NumberOfBytes,
  [in] ULONG                                                 Tag,
  [in] __drv_strictTypeMatch(__drv_typeExpr)EX_POOL_PRIORITY Priority
);