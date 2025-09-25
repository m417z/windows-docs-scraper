PVOID ExAllocatePoolPriorityZero(
  __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
  SIZE_T                                         NumberOfBytes,
  ULONG                                          Tag,
  EX_POOL_PRIORITY                               Priority
);