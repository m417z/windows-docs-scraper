typedef struct _ENDPOINTS_CONFIGURE {
  USBDEVICE_MGMT_HEADER             Header;
  ULONG                             EndpointsToEnableCount;
  UCXENDPOINT                       *EndpointsToEnable;
  ULONG                             EndpointsToDisableCount;
  UCXENDPOINT                       *EndpointsToDisable;
  ULONG                             EndpointsEnabledAndUnchangedCount;
  UCXENDPOINT                       *EndpointsEnabledAndUnchanged;
  ENDPOINTS_CONFIGURE_FAILURE_FLAGS FailureFlags;
  ULONG                             ExitLatencyDelta;
  UCHAR                             ConfigurationValue;
  UCHAR                             InterfaceNumber;
  UCHAR                             AlternateSetting;
  ULONG                             Reserved1;
  PVOID                             Reserved2;
} ENDPOINTS_CONFIGURE, *PENDPOINTS_CONFIGURE;