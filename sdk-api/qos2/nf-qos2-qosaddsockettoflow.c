ExternC BOOL QOSAddSocketToFlow(
  [in]           HANDLE           QOSHandle,
  [in]           SOCKET           Socket,
  [in, optional] PSOCKADDR        DestAddr,
  [in]           QOS_TRAFFIC_TYPE TrafficType,
  [in, optional] DWORD            Flags,
  [in, out]      PQOS_FLOWID      FlowId
);