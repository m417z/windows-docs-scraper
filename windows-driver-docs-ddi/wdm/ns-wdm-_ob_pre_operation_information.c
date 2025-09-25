typedef struct _OB_PRE_OPERATION_INFORMATION {
  OB_OPERATION                 Operation;
  union {
    ULONG Flags;
    struct {
      ULONG KernelHandle : 1;
      ULONG Reserved : 31;
    };
  };
  PVOID                        Object;
  POBJECT_TYPE                 ObjectType;
  PVOID                        CallContext;
  POB_PRE_OPERATION_PARAMETERS Parameters;
} OB_PRE_OPERATION_INFORMATION, *POB_PRE_OPERATION_INFORMATION;