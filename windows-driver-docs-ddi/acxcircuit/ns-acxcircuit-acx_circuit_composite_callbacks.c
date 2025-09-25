typedef struct _ACX_CIRCUIT_COMPOSITE_CALLBACKS {
  ULONG                                        Size;
  PFN_ACX_CIRCUIT_COMPOSITE_CIRCUIT_INITIALIZE EvtAcxCircuitCompositeCircuitInitialize;
  PFN_ACX_CIRCUIT_COMPOSITE_INITIALIZE         EvtAcxCircuitCompositeInitialize;
  PFN_ACX_CIRCUIT_COMPOSITE_DEINITIALIZE       EvtAcxCircuitCompositeDeinitialize;
} ACX_CIRCUIT_COMPOSITE_CALLBACKS, *PACX_CIRCUIT_COMPOSITE_CALLBACKS;