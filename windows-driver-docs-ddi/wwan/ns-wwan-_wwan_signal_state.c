typedef struct _WWAN_SIGNAL_STATE {
  ULONG            Rssi;
  ULONG            ErrorRate;
  ULONG            RssiInterval;
  ULONG            RssiThreshold;
  WWAN_LIST_HEADER SignalStateListHeader;
} WWAN_SIGNAL_STATE, *PWWAN_SIGNAL_STATE;