typedef struct _WUDF_INTERRUPT_CONFIG {
  ULONG                           Size;
  WDF_TRI_STATE                   ShareVector;
  BOOLEAN                         AutomaticSerialization;
  PFN_WUDF_INTERRUPT_ISR          OnInterruptIsr;
  PFN_WUDF_INTERRUPT_ENABLE       OnInterruptEnable;
  PFN_WUDF_INTERRUPT_DISABLE      OnInterruptDisable;
  PFN_WUDF_INTERRUPT_WORKITEM     OnInterruptWorkItem;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR InterruptRaw;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR InterruptTranslated;
} WUDF_INTERRUPT_CONFIG, *PWUDF_INTERRUPT_CONFIG;