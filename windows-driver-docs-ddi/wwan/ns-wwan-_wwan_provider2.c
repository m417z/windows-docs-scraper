typedef struct _WWAN_PROVIDER2 {
  WWAN_PROVIDER       Provider;
  WWAN_CELLULAR_CLASS WwanCellularClass;
  ULONG               Rssi;
  ULONG               ErrorRate;
} WWAN_PROVIDER2, *PWWAN_PROVIDER2;