typedef struct AUDIO_VOLUME_NOTIFICATION_DATA {
  GUID  guidEventContext;
  BOOL  bMuted;
  float fMasterVolume;
  UINT  nChannels;
  float afChannelVolumes[1];
} AUDIO_VOLUME_NOTIFICATION_DATA, *PAUDIO_VOLUME_NOTIFICATION_DATA;