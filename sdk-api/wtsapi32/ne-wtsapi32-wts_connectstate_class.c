typedef enum _WTS_CONNECTSTATE_CLASS {
  WTSActive,
  WTSConnected,
  WTSConnectQuery,
  WTSShadow,
  WTSDisconnected,
  WTSIdle,
  WTSListen,
  WTSReset,
  WTSDown,
  WTSInit
} WTS_CONNECTSTATE_CLASS;