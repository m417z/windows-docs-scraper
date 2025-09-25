typedef struct {
  ULONG            EventId;
  ULONG            DataInput;
  ULONG            ExtraEntryData;
  PFNKSADDEVENT    AddHandler;
  PFNKSREMOVEEVENT RemoveHandler;
  PFNKSHANDLER     SupportHandler;
} KSEVENT_ITEM, *PKSEVENT_ITEM;