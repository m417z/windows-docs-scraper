VOID WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE(
  [out] PWDF_USB_CONTROL_SETUP_PACKET Packet,
  [in]  WDF_USB_BMREQUEST_RECIPIENT   BmRequestRecipient,
  [in]  USHORT                        FeatureSelector,
  [in]  USHORT                        Index,
  [in]  BOOLEAN                       SetFeature
);