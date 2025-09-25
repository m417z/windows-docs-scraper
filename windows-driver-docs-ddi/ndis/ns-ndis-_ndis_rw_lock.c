typedef struct _NDIS_RW_LOCK {
  union {
    struct {
      KSPIN_LOCK SpinLock;
      PVOID      Context;
    };
    UCHAR Reserved[16];
  };
  union {
    NDIS_RW_LOCK_REFCOUNT RefCount[MAXIMUM_PROCESSORS];
    ULONG                 *RefCountEx[sizeof(NDIS_RW_LOCK_REFCOUNT)/ sizeof(ULONG) MAXIMUM_PROCESSORS];
    struct {
      KSPIN_LOCK RefCountLock;
      ULONG      SharedRefCount;
      BOOLEAN    WriterWaiting;
    };
  };
} NDIS_RW_LOCK, *PNDIS_RW_LOCK;