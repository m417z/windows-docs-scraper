void KsFilterGenerateEvents(
  [in]           PKSFILTER                  Filter,
  [in, optional] const GUID                 *EventSet,
  [in]           ULONG                      EventId,
  [in]           ULONG                      DataSize,
  [in]           PVOID                      Data,
  [in, optional] PFNKSGENERATEEVENTCALLBACK CallBack,
  [in, optional] PVOID                      CallBackContext
);