typedef struct AUDIO_MICROPHONE_BOOST_NOTIFICATION {
  IMMDevice *endpoint;
  GUID      eventContext;
  BOOL      microphoneBoostEnabled;
  float     levelInDb;
  float     levelMinInDb;
  float     levelMaxInDb;
  float     levelStepInDb;
  BOOL      muteSupported;
  BOOL      mute;
} AUDIO_MICROPHONE_BOOST_NOTIFICATION;