typedef struct __MIDL___MIDL_itf_eventdetectoroemadapter_0000_0000_0008 {
  EVENTACTIONTYPE        EventdActionType;
  EVENTACTIONCONTEXTTYPE EventActionContextType;
  union {
    float            Confidence;
    EVENTACTIONSCALE Scale;
    HRESULT          ErrorCode;
  };
} EVENTACTION;