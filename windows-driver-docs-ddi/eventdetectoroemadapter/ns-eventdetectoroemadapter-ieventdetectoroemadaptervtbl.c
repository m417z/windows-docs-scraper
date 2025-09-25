typedef struct IEventDetectorOemAdapterVtbl {
  void     *b;
  HRESULT(IEventDetectorOemAdapter *This,REFIID riid, void **ppvObject) * )(QueryInterface;
  ULONG()(IEventDetectorOemAdapter *This)   * AddRef;
  ULONG()(IEventDetectorOemAdapter *This)   * Release;
  HRESULT(tDetectorOemAdapter *This,EVENTFEATURES *GlobalFeatureSupport,LANGID **LangIds,ULONG *NumLanguages,ULONG *NumUserRecordings,WAVEFORMATEX **ppFormat) * )(IEvenGetCapabilities;
  HRESULT(EventDetectorOemAdapter *This,LANGID LangId,DETECTIONEVENT **EventIds,ULONG *NumEvents) * )(IGetCapabilitiesForLanguage;
  HRESULT(IEventDetectorOemAdapter *This,IStream *ModelData,WAVEFORMATEX *UserRecording,DETECTIONEVENTSELECTOR EventSelector,LONG EventEndBytePos) * )(VerifyUserEventData;
  HRESULT(ventDetectorOemAdapter *This,IStream *ModelData,DETECTIONEVENTSELECTOR EventSelector,LONG *EventEndBytePos,WAVEFORMATEX **UserRecordings,ULONG NumUserRecordings) * )(IEComputeAndAddUserModelData;
  HRESULT(ventDetectorOemAdapter *This,IStream *UserModelData,DETECTIONEVENTSELECTOR *EventSelectors,ULONG NumEventSelectors,SOUNDDETECTOR_PATTERNHEADER **PatternData) * )(IEBuildArmingPatternData;
  HRESULT(tectorOemAdapter *This,IStream *UserModelData,SOUNDDETECTOR_PATTERNHEADER *Result,SOUNDDETECTOR_PATTERNHEADER **AssistantContext,DETECTIONEVENTSELECTOR *EventSelector,EVENTACTION *EventAction,ULONG64 *EventStartPerformanceCounterValue,ULONG64 *EventEndPerformanceCounterValue,WCHAR **DebugOutput) * )(IEventDeParseDetectionResultData;
  void()(IEventDetectorOemAdapter *This,DETECTIONEVENTSELECTOR EventSelector,EVENTACTION EventAction)    * ReportOSDetectionResult;
} IEventDetectorOemAdapterVtbl;