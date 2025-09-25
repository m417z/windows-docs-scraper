typedef enum _EVT_SUBSCRIBE_FLAGS {
  EvtSubscribeToFutureEvents = 1,
  EvtSubscribeStartAtOldestRecord = 2,
  EvtSubscribeStartAfterBookmark = 3,
  EvtSubscribeOriginMask = 3,
  EvtSubscribeTolerateQueryErrors = 0x1000,
  EvtSubscribeStrict = 0x10000
} EVT_SUBSCRIBE_FLAGS;