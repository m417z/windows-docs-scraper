NTSTATUS SerCx2PioTransmitCreate(
  [in]           WDFDEVICE                   Device,
  [in]           PSERCX2_PIO_TRANSMIT_CONFIG PioTransmitConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES      Attributes,
  [out]          SERCX2PIOTRANSMIT           *PioTransmit
);