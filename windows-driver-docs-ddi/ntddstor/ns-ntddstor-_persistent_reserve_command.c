typedef struct _PERSISTENT_RESERVE_COMMAND {
  ULONG Version;
  ULONG Size;
  union {
    struct {
      UCHAR  ServiceAction : 5;
      UCHAR  Reserved1 : 3;
      USHORT AllocationLength;
    } PR_IN;
    struct {
      UCHAR ServiceAction : 5;
      UCHAR Reserved1 : 3;
      UCHAR Type : 4;
      UCHAR Scope : 4;
      UCHAR ParameterList[0];
    } PR_OUT;
  } DUMMYUNIONNAME;
} PERSISTENT_RESERVE_COMMAND, *PPERSISTENT_RESERVE_COMMAND;