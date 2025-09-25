typedef struct {
  const GUID         *Set;
  ULONG              EventsCount;
  const KSEVENT_ITEM *EventItem;
} KSEVENT_SET, *PKSEVENT_SET;