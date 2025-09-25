HRESULT ComputeAndAddUserModelData(
  IStream                *ModelData,
  DETECTIONEVENTSELECTOR EventSelector,
  LONG                   *EventEndBytePos,
  WAVEFORMATEX           **UserRecordings,
  ULONG                  NumUserRecordings
);