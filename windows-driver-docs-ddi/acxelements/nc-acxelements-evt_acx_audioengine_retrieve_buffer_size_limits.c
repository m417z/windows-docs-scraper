EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS EvtAcxAudioengineRetrieveBufferSizeLimits;

NTSTATUS EvtAcxAudioengineRetrieveBufferSizeLimits(
  ACXAUDIOENGINE AudioEngine,
  ACXDATAFORMAT Format,
  PULONG MinBufferSizeInBytes,
  PULONG MaxBufferSizeInBytes
)
{...}