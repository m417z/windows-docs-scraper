typedef struct _AUDIO_SENSORS_INTERFACE_V0100 {
  INTERFACE                            InterfaceHeader;
  PFN_AUDIO_SENSORS_START_SESSION      EvtAudioSensorsStartSession;
  PFN_AUDIO_SENSORS_STOP_SESSION       EvtAudioSensorsStopSession;
  PFN_AUDIO_SENSORS_GET_BUFFER         EvtAudioSensorsGetBuffer;
  PFN_AUDIO_SENSORS_SET_BUFFER         EvtAudioSensorsSetBuffer;
  PFN_AUDIO_SENSORS_SUBMIT_READ_REPORT EvtAudioSensorsSubmitReadReport;
} AUDIO_SENSORS_INTERFACE_V0100, *PAUDIO_SENSORS_INTERFACE_V0100;