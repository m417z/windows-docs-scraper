VOID WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR(
  [out] PWDF_USB_CONTROL_SETUP_PACKET Packet,
  [in]  WDF_USB_BMREQUEST_DIRECTION   Direction,
  [in]  WDF_USB_BMREQUEST_RECIPIENT   Recipient,
  [in]  BYTE                          Request,
  [in]  USHORT                        Value,
  [in]  USHORT                        Index
);