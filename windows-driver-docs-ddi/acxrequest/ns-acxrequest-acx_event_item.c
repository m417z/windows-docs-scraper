typedef struct _ACX_EVENT_ITEM {
  const GUID                           *Set;
  ULONG                                Id;
  ULONG                                Flags;
  PFN_ACX_OBJECT_PROCESS_EVENT_REQUEST EvtAcxObjectProcessRequest;
  PVOID                                Reserved;
} ACX_EVENT_ITEM, *PACX_EVENT_ITEM;