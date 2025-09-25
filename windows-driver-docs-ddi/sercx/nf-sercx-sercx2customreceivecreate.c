NTSTATUS SerCx2CustomReceiveCreate(
  [in]  WDFDEVICE                     Device,
  [in]  PSERCX2_CUSTOM_RECEIVE_CONFIG CustomReceiveConfig,
  [in]  PWDF_OBJECT_ATTRIBUTES        Attributes,
  [out] SERCX2CUSTOMRECEIVE           *CustomReceive
);