EVT_AUDIO_SENSORS_STOP_SESSION EvtAudioSensorsStopSession;

NTSTATUS EvtAudioSensorsStopSession(
  PVOID Context,
  AUDIO_MODULE_ID ModuleId,
  ULONG SensorsSessionId
)
{...}