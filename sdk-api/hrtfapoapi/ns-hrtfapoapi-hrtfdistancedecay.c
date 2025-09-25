typedef struct HrtfDistanceDecay {
  HrtfDistanceDecayType type;
  float                 maxGain;
  float                 minGain;
  float                 unityGainDistance;
  float                 cutoffDistance;
} HrtfDistanceDecay;