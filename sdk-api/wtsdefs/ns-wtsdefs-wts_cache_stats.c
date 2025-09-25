typedef struct _WTS_CACHE_STATS {
  DWORD              Specific;
  WTS_CACHE_STATS_UN Data;
  USHORT             ProtocolType;
  USHORT             Length;
} _WTS_CACHE_STATS, WTS_CACHE_STATS, *PWTS_CACHE_STATS, _WRDS_CACHE_STATS;