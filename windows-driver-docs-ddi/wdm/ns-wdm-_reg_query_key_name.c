typedef struct _REG_QUERY_KEY_NAME {
  PVOID                    Object;
  POBJECT_NAME_INFORMATION ObjectNameInfo;
  ULONG                    Length;
  PULONG                   ReturnLength;
  PVOID                    CallContext;
  PVOID                    ObjectContext;
  PVOID                    Reserved;
} REG_QUERY_KEY_NAME, *PREG_QUERY_KEY_NAME;