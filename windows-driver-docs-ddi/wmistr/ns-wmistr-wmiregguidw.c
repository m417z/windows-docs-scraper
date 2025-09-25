typedef struct {
  GUID  Guid;
  ULONG Flags;
  ULONG InstanceCount;
  union {
    ULONG     InstanceNameList;
    ULONG     BaseNameOffset;
    ULONG_PTR Pdo;
    ULONG_PTR InstanceInfo;
  } DUMMYUNIONNAME;
} WMIREGGUIDW, *PWMIREGGUIDW;