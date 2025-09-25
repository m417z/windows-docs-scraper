typedef struct _DXGK_TIMED_OPERATION {
  [in]  USHORT        Size;
        ULONG_PTR     OwnerTag;
        BOOLEAN       OsHandled;
  [out] BOOLEAN       TimeoutTriggered;
        LARGE_INTEGER Timeout;
        LARGE_INTEGER StartTick;
} DXGK_TIMED_OPERATION, *PDXGK_TIMED_OPERATION;