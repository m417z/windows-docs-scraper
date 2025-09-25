NTSTATUS SerCx2SystemDmaTransmitCreate(
  [in]           WDFDEVICE                          Device,
  [in]           PSERCX2_SYSTEM_DMA_TRANSMIT_CONFIG SystemDmaTransmitConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES             Attributes,
  [out]          SERCX2SYSTEMDMATRANSMIT            *SystemDmaTransmit
);