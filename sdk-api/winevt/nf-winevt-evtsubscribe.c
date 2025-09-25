EVT_HANDLE EvtSubscribe(
  [in] EVT_HANDLE             Session,
  [in] HANDLE                 SignalEvent,
  [in] LPCWSTR                ChannelPath,
  [in] LPCWSTR                Query,
  [in] EVT_HANDLE             Bookmark,
  [in] PVOID                  Context,
  [in] EVT_SUBSCRIBE_CALLBACK Callback,
  [in] DWORD                  Flags
);