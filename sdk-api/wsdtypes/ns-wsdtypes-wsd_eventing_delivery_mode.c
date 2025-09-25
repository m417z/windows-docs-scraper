typedef struct _WSD_EVENTING_DELIVERY_MODE {
  const WCHAR                     *Mode;
  WSD_EVENTING_DELIVERY_MODE_PUSH *Push;
  void                            *Data;
} WSD_EVENTING_DELIVERY_MODE;