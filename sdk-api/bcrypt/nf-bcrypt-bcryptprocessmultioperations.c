NTSTATUS BCryptProcessMultiOperations(
  BCRYPT_HANDLE               hObject,
  BCRYPT_MULTI_OPERATION_TYPE operationType,
  PVOID                       pOperations,
  ULONG                       cbOperations,
  ULONG                       dwFlags
);