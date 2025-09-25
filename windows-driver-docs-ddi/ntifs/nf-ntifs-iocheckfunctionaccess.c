NTSTATUS IoCheckFunctionAccess(
  ACCESS_MASK GrantedAccess,
  UCHAR       MajorFunction,
  UCHAR       MinorFunction,
  ULONG       IoControlCode,
  PVOID       Arg1,
  PVOID       Arg2
);