EVT_ACX_STREAM_GET_PRESENTATION_POSITION EvtAcxStreamGetPresentationPosition;

NTSTATUS EvtAcxStreamGetPresentationPosition(
  ACXSTREAM Stream,
  PULONGLONG PositionInBlocks,
  PULONGLONG QPCPosition
)
{...}