typedef enum _QOS_TRAFFIC_TYPE {
  QOSTrafficTypeBestEffort = 0,
  QOSTrafficTypeBackground = 1,
  QOSTrafficTypeExcellentEffort = 2,
  QOSTrafficTypeAudioVideo = 3,
  QOSTrafficTypeVoice = 4,
  QOSTrafficTypeControl = 5
} QOS_TRAFFIC_TYPE, *PQOS_TRAFFIC_TYPE;