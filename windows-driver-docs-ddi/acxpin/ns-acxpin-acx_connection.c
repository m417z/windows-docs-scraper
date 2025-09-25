typedef struct _ACX_CONNECTION {
  ULONG     Size;
  ULONG     Flags;
  ACXOBJECT FromObject;
  union {
    ACXPIN Object;
    ULONG  Id;
  } FromPin;
  ACXOBJECT ToObject;
  union {
    ACXPIN Object;
    ULONG  Id;
  } ToPin;
} ACX_CONNECTION, *PACX_CONNECTION;