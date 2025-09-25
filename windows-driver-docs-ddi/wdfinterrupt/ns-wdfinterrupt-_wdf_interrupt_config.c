typedef struct _WDF_INTERRUPT_CONFIG {
  ULONG                           Size;
  WDFSPINLOCK                     SpinLock;
  WDF_TRI_STATE                   ShareVector;
  BOOLEAN                         FloatingSave;
  BOOLEAN                         AutomaticSerialization;
  PFN_WDF_INTERRUPT_ISR           EvtInterruptIsr;
  PFN_WDF_INTERRUPT_DPC           EvtInterruptDpc;
  PFN_WDF_INTERRUPT_ENABLE        EvtInterruptEnable;
  PFN_WDF_INTERRUPT_DISABLE       EvtInterruptDisable;
  PFN_WDF_INTERRUPT_WORKITEM      EvtInterruptWorkItem;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR InterruptRaw;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR InterruptTranslated;
  WDFWAITLOCK                     WaitLock;
  BOOLEAN                         PassiveHandling;
  WDF_TRI_STATE                   ReportInactiveOnPowerDown;
  BOOLEAN                         CanWakeDevice;
} WDF_INTERRUPT_CONFIG, *PWDF_INTERRUPT_CONFIG;