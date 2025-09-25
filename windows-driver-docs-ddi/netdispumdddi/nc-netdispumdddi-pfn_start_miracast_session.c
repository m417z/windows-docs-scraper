PFN_START_MIRACAST_SESSION PfnStartMiracastSession;

NTSTATUS PfnStartMiracastSession(
  [in]  PVOID pMiracastContext,
  [in]  SOCKET MiracastRTSPSocket,
  [in]  MIRACAST_WFD_CONNECTION_STATS *pWfdConnectionStats,
  [out] MIRACAST_SESSION_INFO *pSessionInfo
)
{...}