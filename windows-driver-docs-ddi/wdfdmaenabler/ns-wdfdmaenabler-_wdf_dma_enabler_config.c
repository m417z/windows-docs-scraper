typedef struct _WDF_DMA_ENABLER_CONFIG {
  ULONG                                    Size;
  WDF_DMA_PROFILE                          Profile;
  size_t                                   MaximumLength;
  PFN_WDF_DMA_ENABLER_FILL                 EvtDmaEnablerFill;
  PFN_WDF_DMA_ENABLER_FLUSH                EvtDmaEnablerFlush;
  PFN_WDF_DMA_ENABLER_DISABLE              EvtDmaEnablerDisable;
  PFN_WDF_DMA_ENABLER_ENABLE               EvtDmaEnablerEnable;
  PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START EvtDmaEnablerSelfManagedIoStart;
  PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP  EvtDmaEnablerSelfManagedIoStop;
  ULONG                                    AddressWidthOverride;
  ULONG                                    WdmDmaVersionOverride;
  ULONG                                    Flags;
} WDF_DMA_ENABLER_CONFIG, *PWDF_DMA_ENABLER_CONFIG;