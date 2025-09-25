ExternC BOOL QOSQueryFlow(
  [in]            HANDLE         QOSHandle,
  [in]            QOS_FLOWID     FlowId,
  [in]            QOS_QUERY_FLOW Operation,
  [in, out]       PULONG         Size,
  [out]           PVOID          Buffer,
  [in, optional]  DWORD          Flags,
  [out, optional] LPOVERLAPPED   Overlapped
);