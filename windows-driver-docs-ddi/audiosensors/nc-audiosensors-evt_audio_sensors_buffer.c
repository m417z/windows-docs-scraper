EVT_AUDIO_SENSORS_BUFFER EvtAudioSensorsBuffer;

NTSTATUS EvtAudioSensorsBuffer(
  PVOID Context,
  AUDIO_MODULE_ID ModuleId,
  ULONG SensorsSessionId,
  PULONG BufferSize,
  PVOID Buffer
)
{...}