typedef struct {
  DS3DVECTOR Position;
  DS3DVECTOR Velocity;
  DS3DVECTOR OrientFront;
  DS3DVECTOR OrientTop;
  FLOAT      DistanceFactor;
  FLOAT      RolloffFactor;
  FLOAT      DopplerFactor;
} KSDS3D_LISTENER_ALL, *PKSDS3D_LISTENER_ALL;