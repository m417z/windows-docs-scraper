ExternC BOOL QOSNotifyFlow(
  [in]                HANDLE          QOSHandle,
  [in]                QOS_FLOWID      FlowId,
  [in]                QOS_NOTIFY_FLOW Operation,
  [in, out, optional] PULONG          Size,
  [in, out]           PVOID           Buffer,
                      DWORD           Flags,
  [out, optional]     LPOVERLAPPED    Overlapped
);