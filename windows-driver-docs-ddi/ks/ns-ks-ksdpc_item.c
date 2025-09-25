typedef struct {
  KDPC       Dpc;
  ULONG      ReferenceCount;
  KSPIN_LOCK AccessLock;
} KSDPC_ITEM, *PKSDPC_ITEM;