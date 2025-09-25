typedef struct {
  const GUID         *Set;
  ULONG              Id;
  ULONG              Flags;
  PCPFNEVENT_HANDLER Handler;
} PCEVENT_ITEM, *PPCEVENT_ITEM;