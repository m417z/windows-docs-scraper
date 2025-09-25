typedef enum _EVT_SEEK_FLAGS {
  EvtSeekRelativeToFirst = 1,
  EvtSeekRelativeToLast = 2,
  EvtSeekRelativeToCurrent = 3,
  EvtSeekRelativeToBookmark = 4,
  EvtSeekOriginMask = 7,
  EvtSeekStrict = 0x10000
} EVT_SEEK_FLAGS;