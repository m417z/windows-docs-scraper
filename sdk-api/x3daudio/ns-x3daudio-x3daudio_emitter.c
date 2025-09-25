typedef struct X3DAUDIO_EMITTER {
  X3DAUDIO_CONE           *pCone;
  X3DAUDIO_VECTOR         OrientFront;
  X3DAUDIO_VECTOR         OrientTop;
  X3DAUDIO_VECTOR         Position;
  X3DAUDIO_VECTOR         Velocity;
  FLOAT32                 InnerRadius;
  FLOAT32                 InnerRadiusAngle;
  UINT32                  ChannelCount;
  FLOAT32                 ChannelRadius;
  FLOAT32                 *pChannelAzimuths;
  X3DAUDIO_DISTANCE_CURVE *pVolumeCurve;
  X3DAUDIO_DISTANCE_CURVE *pLFECurve;
  X3DAUDIO_DISTANCE_CURVE *pLPFDirectCurve;
  X3DAUDIO_DISTANCE_CURVE *pLPFReverbCurve;
  X3DAUDIO_DISTANCE_CURVE *pReverbCurve;
  FLOAT32                 CurveDistanceScaler;
  FLOAT32                 DopplerScaler;
} X3DAUDIO_EMITTER, *LPX3DAUDIO_EMITTER;