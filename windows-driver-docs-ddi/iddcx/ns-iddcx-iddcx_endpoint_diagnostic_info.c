struct IDDCX_ENDPOINT_DIAGNOSTIC_INFO {
  UINT                         Size;
  IDDCX_TRANSMISSION_TYPE      TransmissionType;
  PCWSTR                       pEndPointFriendlyName;
  PCWSTR                       pEndPointModelName;
  PCWSTR                       pEndPointManufacturerName;
  IDDCX_ENDPOINT_VERSION       *pHardwareVersion;
  IDDCX_ENDPOINT_VERSION       *pFirmwareVersion;
  IDDCX_FEATURE_IMPLEMENTATION GammaSupport;
};