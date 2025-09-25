BOOL GetMailslotInfo(
  [in]            HANDLE  hMailslot,
  [out, optional] LPDWORD lpMaxMessageSize,
  [out, optional] LPDWORD lpNextSize,
  [out, optional] LPDWORD lpMessageCount,
  [out, optional] LPDWORD lpReadTimeout
);