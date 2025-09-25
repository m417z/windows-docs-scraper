typedef struct _PosMagneticStripeReaderCapabilitiesType {
  DriverUnifiedPosPowerReportingType            PowerReportingType;
  LONG                                          IsStatisticsReportingSupported;
  LONG                                          IsStatisticsUpdatingSupported;
  UINT32                                        CardAuthenticationLength;
  UINT32                                        SupportedEncryptionAlgorithms;
  DriverMagneticStripeReaderAuthenticationLevel AuthenticationLevel;
  LONG                                          IsIsoSupported;
  LONG                                          IsJisOneSupported;
  LONG                                          IsJisTwoSupported;
  LONG                                          IsTrackDataMaskingSupported;
  LONG                                          IsTransmitSentinelsSupported;
} PosMagneticStripeReaderCapabilitiesType;