PVOID ExAllocatePoolWithTag(
  [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
  [in] SIZE_T                                         NumberOfBytes,
  [in] ULONG                                          Tag
);