typedef struct _ACX_METHOD_ITEM {
  const GUID                     *Set;
  ULONG                          Id;
  ULONG                          Flags;
  PFN_ACX_OBJECT_PROCESS_REQUEST EvtAcxObjectProcessRequest;
  PVOID                          Reserved;
  ULONG                          ArgsCb;
  ULONG                          ResultCb;
  ULONG                          ResultType;
} ACX_METHOD_ITEM, *PACX_METHOD_ITEM;