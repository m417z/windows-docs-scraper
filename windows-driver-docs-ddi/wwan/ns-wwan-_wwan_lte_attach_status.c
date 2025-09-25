typedef struct _WWAN_LTE_ATTACH_STATUS {
  WWAN_CONTEXT_LTE_ATTACH_STATE LteAttachState;
  WWAN_IP_TYPE                  IPType;
  WWAN_CONTEXT                  basicInfo;
  ULONG                         NetworkError;
} WWAN_LTE_ATTACH_STATUS, *PWWAN_LTE_ATTACH_STATUS;