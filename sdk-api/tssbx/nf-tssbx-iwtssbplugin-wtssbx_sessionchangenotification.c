HRESULT WTSSBX_SessionChangeNotification(
  [in] WTSSBX_NOTIFICATION_TYPE NotificationType,
  [in] long                     MachineId,
  [in] DWORD                    NumOfSessions,
  [in] WTSSBX_SESSION_INFO []   SessionInfo
);