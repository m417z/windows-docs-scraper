EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION EvtAcxStreamaudioengineRetrievePresentationPosition;

NTSTATUS EvtAcxStreamaudioengineRetrievePresentationPosition(
  ACXSTREAMAUDIOENGINE StreamAudioEngine,
  PULONGLONG PositionInBlocks,
  PULONGLONG QPCPosition
)
{...}