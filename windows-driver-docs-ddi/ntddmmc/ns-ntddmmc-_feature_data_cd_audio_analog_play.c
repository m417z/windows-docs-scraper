typedef struct _FEATURE_DATA_CD_AUDIO_ANALOG_PLAY {
  FEATURE_HEADER Header;
  UCHAR          SeperateVolume : 1;
  UCHAR          SeperateChannelMute : 1;
  UCHAR          ScanSupported : 1;
  UCHAR          Reserved1 : 5;
  UCHAR          Reserved2;
  UCHAR          NumerOfVolumeLevels[2];
} FEATURE_DATA_CD_AUDIO_ANALOG_PLAY, *PFEATURE_DATA_CD_AUDIO_ANALOG_PLAY;