typedef struct _PCEVENT_REQUEST {
  PUNKNOWN           MajorTarget;
  PUNKNOWN           MinorTarget;
  ULONG              Node;
  const PCEVENT_ITEM *EventItem;
  PKSEVENT_ENTRY     EventEntry;
  ULONG              Verb;
  PIRP               Irp;
} PCEVENT_REQUEST, *PPCEVENT_REQUEST;