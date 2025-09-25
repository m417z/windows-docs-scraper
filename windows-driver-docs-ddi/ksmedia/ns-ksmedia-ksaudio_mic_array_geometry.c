typedef struct {
  USHORT                         usVersion;
  USHORT                         usMicArrayType;
  SHORT                          wVerticalAngleBegin;
  SHORT                          wVerticalAngleEnd;
  SHORT                          wHorizontalAngleBegin;
  SHORT                          wHorizontalAngleEnd;
  USHORT                         usFrequencyBandLo;
  USHORT                         usFrequencyBandHi;
  USHORT                         usNumberOfMicrophones;
  KSAUDIO_MICROPHONE_COORDINATES KsMicCoord[1];
} KSAUDIO_MIC_ARRAY_GEOMETRY, *PKSAUDIO_MIC_ARRAY_GEOMETRY;