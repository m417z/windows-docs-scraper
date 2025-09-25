typedef struct _UDECX_USB_ENDPOINT_INIT_AND_METADATA {
  PUDECXUSBENDPOINT_INIT                        UdecxUsbEndpointInit;
  ULONG                                         EndpointDescriptorBufferLength;
  PUSB_ENDPOINT_DESCRIPTOR                      EndpointDescriptor;
  PUSB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR SuperSpeedEndpointCompanionDescriptor;
} UDECX_USB_ENDPOINT_INIT_AND_METADATA, *PUDECX_USB_ENDPOINT_INIT_AND_METADATA;