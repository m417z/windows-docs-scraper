EVT_ACX_MUTE_RETRIEVE_STATE EvtAcxMuteRetrieveState;

NTSTATUS EvtAcxMuteRetrieveState(
  ACXMUTE Mute,
  ULONG Channel,
  ULONG *State
)
{...}