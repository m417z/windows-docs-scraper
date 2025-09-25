typedef struct _WSD_EVENTING_FILTER {
  const WCHAR                *Dialect;
  WSD_EVENTING_FILTER_ACTION *FilterAction;
  void                       *Data;
} WSD_EVENTING_FILTER;