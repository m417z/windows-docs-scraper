typedef struct WCM_BILLING_CYCLE_INFO {
  FILETIME          StartDate;
  WCM_TIME_INTERVAL Duration;
  BOOL              Reset;
} WCM_BILLING_CYCLE_INFO;