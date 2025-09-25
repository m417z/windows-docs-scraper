typedef struct _WWAN_LTE_ATTACH_CONFIG {
  ULONG           ElementCount;
  WWAN_CONTEXT_V2 LteContextArray[TotalRoamingConditions];
} WWAN_LTE_ATTACH_CONFIG, *PWWAN_LTE_ATTACH_CONFIG;