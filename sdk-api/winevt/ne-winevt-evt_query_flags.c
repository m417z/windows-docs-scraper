typedef enum _EVT_QUERY_FLAGS {
  EvtQueryChannelPath = 0x1,
  EvtQueryFilePath = 0x2,
  EvtQueryForwardDirection = 0x100,
  EvtQueryReverseDirection = 0x200,
  EvtQueryTolerateQueryErrors = 0x1000
} EVT_QUERY_FLAGS;