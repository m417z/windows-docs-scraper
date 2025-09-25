NTSTATUS SerCx2CustomTransmitCreate(
  [in]  WDFDEVICE                      Device,
  [in]  PSERCX2_CUSTOM_TRANSMIT_CONFIG CustomTransmitConfig,
  [in]  PWDF_OBJECT_ATTRIBUTES         Attributes,
  [out] SERCX2CUSTOMTRANSMIT           *CustomTransmit
);