typedef struct _ACX_PROPERTY_ITEM {
  const GUID                     *Set;
  ULONG                          Id;
  ULONG                          Flags;
  PFN_ACX_OBJECT_PROCESS_REQUEST EvtAcxObjectProcessRequest;
  PVOID                          Reserved;
  ULONG                          ControlCb;
  ULONG                          ValueCb;
  ULONG                          ValueType;
} ACX_PROPERTY_ITEM, *PACX_PROPERTY_ITEM;