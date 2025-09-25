typedef struct _STOR_DISPATCHER_HEADER {
  union {
    struct {
      UCHAR Type;
      UCHAR Flags;
      UCHAR Size;
      union {
        UCHAR   Inserted;
        BOOLEAN DebugActive;
      };
    } Data;
    LONG Lock;
  };
  LONG            SignalState;
  STOR_LIST_ENTRY WaitListHead;
} STOR_DISPATCHER_HEADER, *PSTOR_DISPATCHER_HEADER;