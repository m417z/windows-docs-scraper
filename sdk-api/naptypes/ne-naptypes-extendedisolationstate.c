typedef enum tagExtendedIsolationState {
  extendedIsolationStateNoData = 0,
  extendedIsolationStateTransition = 0x1,
  extendedIsolationStateInfected = 0x2,
  extendedIsolationStateUnknown = 0x3
} ExtendedIsolationState;