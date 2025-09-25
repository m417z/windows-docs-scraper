void KsPinGenerateEvents(
  [in]           PKSPIN                     Pin,
  [in, optional] const GUID                 *EventSet,
  [in]           ULONG                      EventId,
  [in]           ULONG                      DataSize,
  [in, optional] PVOID                      Data,
  [in, optional] PFNKSGENERATEEVENTCALLBACK CallBack,
  [in, optional] PVOID                      CallBackContext
);