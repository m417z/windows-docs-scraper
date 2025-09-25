typedef struct APO_NOTIFICATION {
  APO_NOTIFICATION_TYPE type;
  union {
    AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION        audioEndpointVolumeChange;
    AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION      audioEndpointPropertyChange;
    AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION audioSystemEffectsPropertyChange;
    AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION2       audioEndpointVolumeChange2;
    DEVICE_ORIENTATION_TYPE                          deviceOrientation;
    AUDIO_MICROPHONE_BOOST_NOTIFICATION              audioMicrophoneBoostChange;
    AUDIO_ENVIRONMENT_STATE_CHANGE_NOTIFICATION      audioEnvironmentChange;
  } DUMMYUNIONNAME;
} APO_NOTIFICATION;