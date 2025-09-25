typedef struct _WDF_WORKITEM_CONFIG {
  ULONG            Size;
  PFN_WDF_WORKITEM EvtWorkItemFunc;
  BOOLEAN          AutomaticSerialization;
} WDF_WORKITEM_CONFIG, *PWDF_WORKITEM_CONFIG;