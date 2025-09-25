typedef enum _WWAN_READY_STATE {
  WwanReadyStateOff,
  WwanReadyStateInitialized,
  WwanReadyStateSimNotInserted,
  WwanReadyStateBadSim,
  WwanReadyStateFailure,
  WwanReadyStateNotActivated,
  WwanReadyStateDeviceLocked,
  WwanReadyStateNoEsimProfile,
  WwanReadyStateMax
} WWAN_READY_STATE, *PWWAN_READY_STATE;