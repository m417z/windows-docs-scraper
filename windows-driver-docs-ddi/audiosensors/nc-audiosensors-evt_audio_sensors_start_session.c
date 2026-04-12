EVT_AUDIO_SENSORS_START_SESSION EvtAudioSensorsStartSession;

NTSTATUS EvtAudioSensorsStartSession(
  PVOID Context,
  AUDIO_MODULE_ID ModuleId,
  PAUDIO_ENDPOINT_CONFIG AudioRenderEndpointConfig,
  PAUDIO_ENDPOINT_CONFIG AudioCaptureEndpointConfig,
  PULONG SensorsSessionId
)
{...}