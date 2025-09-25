typedef struct AUDIO_VOLUME_NOTIFICATION_DATA2 {
  PAUDIO_VOLUME_NOTIFICATION_DATA notificationData;
  float                           masterVolumeInDb;
  float                           volumeMinInDb;
  float                           volumeMaxInDb;
  float                           volumeIncrementInDb;
  UINT                            step;
  UINT                            stepCount;
  float                           channelVolumesInDb[1];
} AUDIO_VOLUME_NOTIFICATION_DATA2, *PAUDIO_VOLUME_NOTIFICATION_DATA2;