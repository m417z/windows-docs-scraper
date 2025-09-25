typedef struct X3DAUDIO_DSP_SETTINGS {
  FLOAT32 *pMatrixCoefficients;
  FLOAT32 *pDelayTimes;
  UINT32  SrcChannelCount;
  UINT32  DstChannelCount;
  FLOAT32 LPFDirectCoefficient;
  FLOAT32 LPFReverbCoefficient;
  FLOAT32 ReverbLevel;
  FLOAT32 DopplerFactor;
  FLOAT32 EmitterToListenerAngle;
  FLOAT32 EmitterToListenerDistance;
  FLOAT32 EmitterVelocityComponent;
  FLOAT32 ListenerVelocityComponent;
} X3DAUDIO_DSP_SETTINGS, *LPX3DAUDIO_DSP_SETTINGS;