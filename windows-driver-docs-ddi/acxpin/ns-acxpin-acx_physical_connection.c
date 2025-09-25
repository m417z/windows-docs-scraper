typedef struct _ACX_PHYSICAL_CONNECTION {
  ULONG     Size;
  ULONG     Flags;
  union {
    ACXPIN Object;
    ULONG  Id;
  } FromPin;
  WDFSTRING TargetName;
  ULONG     TargetPinId;
} ACX_PHYSICAL_CONNECTION, *PACX_PHYSICAL_CONNECTION;