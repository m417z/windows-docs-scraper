typedef struct _WWAN_SET_UICC_RESET {
  WWAN_UICC_PASSTHROUGH_ACTION PassThroughAction;
  ULONG                        SlotId;
} WWAN_SET_UICC_RESET, *PWWAN_SET_UICC_RESET;