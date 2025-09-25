EVT_ACX_AUDIOMODULE_PROCESSCOMMAND EvtAcxAudiomoduleProcesscommand;

NTSTATUS EvtAcxAudiomoduleProcesscommand(
  ACXAUDIOMODULE AudioModule,
  PVOID InBuffer,
  ULONG InBufferCb,
  PVOID OutBuffer,
  PULONG OutBufferCb
)
{...}