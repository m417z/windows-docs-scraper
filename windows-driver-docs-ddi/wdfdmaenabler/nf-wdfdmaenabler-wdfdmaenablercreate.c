NTSTATUS WdfDmaEnablerCreate(
  [in]           WDFDEVICE               Device,
  [in]           PWDF_DMA_ENABLER_CONFIG Config,
  [in, optional] PWDF_OBJECT_ATTRIBUTES  Attributes,
  [out]          WDFDMAENABLER           *DmaEnablerHandle
);