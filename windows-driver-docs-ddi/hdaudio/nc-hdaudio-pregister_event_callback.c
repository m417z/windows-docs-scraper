PREGISTER_EVENT_CALLBACK PregisterEventCallback;

NTSTATUS PregisterEventCallback(
  [in]  PVOID _context,
  [in]  PHDAUDIO_UNSOLICITED_RESPONSE_CALLBACK Routine,
  [in]  PVOID Context,
  [out] PUCHAR Tag
)
{...}