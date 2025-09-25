typedef struct _REG_POST_OPERATION_INFORMATION {
  PVOID    Object;
  NTSTATUS Status;
  PVOID    PreInformation;
  NTSTATUS ReturnStatus;
  PVOID    CallContext;
  PVOID    ObjectContext;
  PVOID    Reserved;
} REG_POST_OPERATION_INFORMATION, *PREG_POST_OPERATION_INFORMATION;