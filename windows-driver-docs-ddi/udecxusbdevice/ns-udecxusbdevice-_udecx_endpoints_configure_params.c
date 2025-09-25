typedef struct _UDECX_ENDPOINTS_CONFIGURE_PARAMS {
  ULONG                          Size;
  UDECX_ENDPOINTS_CONFIGURE_TYPE ConfigureType;
  UCHAR                          NewConfigurationValue;
  UCHAR                          InterfaceNumber;
  UCHAR                          NewInterfaceSetting;
  ULONG                          EndpointsToConfigureCount;
  UDECXUSBENDPOINT               *EndpointsToConfigure;
  ULONG                          ReleasedEndpointsCount;
  UDECXUSBENDPOINT               *ReleasedEndpoints;
} UDECX_ENDPOINTS_CONFIGURE_PARAMS, *PUDECX_ENDPOINTS_CONFIGURE_PARAMS;