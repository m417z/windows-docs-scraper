typedef enum _COPP_ConnectorType {
  COPP_ConnectorType_Unknown = -1,
  COPP_ConnectorType_VGA = 0,
  COPP_ConnectorType_SVideo = 1,
  COPP_ConnectorType_CompositeVideo = 2,
  COPP_ConnectorType_ComponentVideo = 3,
  COPP_ConnectorType_DVI = 4,
  COPP_ConnectorType_HDMI = 5,
  COPP_ConnectorType_LVDS = 6,
  COPP_ConnectorType_TMDS = 7,
  COPP_ConnectorType_D_JPN = 8,
  COPP_ConnectorType_Internal = 0x80000000,
  COPP_ConnectorType_ForceDWORD
} COPP_ConnectorType;