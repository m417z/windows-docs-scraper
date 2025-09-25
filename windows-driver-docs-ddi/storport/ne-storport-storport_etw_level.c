typedef enum _STORPORT_ETW_LEVEL {
  StorportEtwLevelLogAlways = 0,
  StorportEtwLevelCritical = 1,
  StorportEtwLevelError = 2,
  StorportEtwLevelWarning = 3,
  StorportEtwLevelInformational = 4,
  StorportEtwLevelVerbose = 5,
  StorportEtwLevelMax
} STORPORT_ETW_LEVEL, *PSTORPORT_ETW_LEVEL;