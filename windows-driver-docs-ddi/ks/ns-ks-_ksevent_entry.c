typedef struct _KSEVENT_ENTRY {
  LIST_ENTRY         ListEntry;
  PVOID              Object;
  union {
    PKSDPC_ITEM    DpcItem;
    PKSBUFFER_ITEM BufferItem;
  };
  PKSEVENTDATA       EventData;
  ULONG              NotificationType;
  const KSEVENT_SET  *EventSet;
  const KSEVENT_ITEM *EventItem;
  PFILE_OBJECT       FileObject;
  ULONG              SemaphoreAdjustment;
  ULONG              Reserved;
  ULONG              Flags;
} KSEVENT_ENTRY, *PKSEVENT_ENTRY;