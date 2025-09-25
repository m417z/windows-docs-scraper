typedef struct _WWAN_MODEM_LOGGING_CONFIG {
  ULONG                           Version;
  ULONG                           MaxSegmentSize;
  ULONG                           MaxFlushTime;
  WWAN_MODEM_LOGGING_LEVEL_CONFIG LevelConfig;
} WWAN_MODEM_LOGGING_CONFIG, *PWWAN_MODEM_LOGGING_CONFIG;