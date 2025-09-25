HRESULT ParseDetectionResultData(
  IStream                     *UserModelData,
  SOUNDDETECTOR_PATTERNHEADER *Result,
  SOUNDDETECTOR_PATTERNHEADER **AssistantContext,
  DETECTIONEVENTSELECTOR      *EventSelector,
  EVENTACTION                 *EventAction,
  ULONG64                     *EventStartPerformanceCounterValue,
  ULONG64                     *EventEndPerformanceCounterValue,
  WCHAR                       **DebugOutput
);