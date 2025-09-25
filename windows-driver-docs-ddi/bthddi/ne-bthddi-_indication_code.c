typedef enum _INDICATION_CODE {
  IndicationAddReference,
  IndicationReleaseReference,
  IndicationRemoteConnect,
  IndicationRemoteDisconnect,
  IndicationRemoteConfigRequest,
  IndicationRemoteConfigResponse,
  IndicationFreeExtraOptions,
  IndicationRecvPacket,
  IndicationPairDevice,
  IndicationUnpairDevice,
  IndicationUnpersonalizeDevice,
  IndicationRemoteConnectLE
} INDICATION_CODE, *PINDICATION_CODE;