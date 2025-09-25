typedef enum _WWAN_UICCSLOT_STATE {
  WwanUiccSlotStateUnknown,
  WwanUiccSlotStateOffEmpty,
  WwanUiccSlotStateOff,
  WwanUiccSlotStateEmpty,
  WwanUiccSlotStateNotReady,
  WwanUiccSlotStateActive,
  WwanUiccSlotStateError,
  WwanUiccSlotStateActiveEsim,
  WwanUiccSlotStateActiveEsimNoProfile,
  WwanUiccSlotStateMax
} WWAN_UICCSLOT_STATE, *PWWAN_UICCSLOT_STATE;