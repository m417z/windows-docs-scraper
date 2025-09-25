typedef struct {
  FAST_MUTEX       Mutex;
  PRTL_SPLAY_LINKS Cache;
  LIST_ENTRY       TimerQueue;
  USHORT           NumEntries;
} TUNNEL, *PTUNNEL;