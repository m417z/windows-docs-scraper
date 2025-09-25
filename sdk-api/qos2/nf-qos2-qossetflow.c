ExternC BOOL QOSSetFlow(
  [in]            HANDLE       QOSHandle,
  [in]            QOS_FLOWID   FlowId,
  [in]            QOS_SET_FLOW Operation,
  [in]            ULONG        Size,
  [in]            PVOID        Buffer,
                  DWORD        Flags,
  [out, optional] LPOVERLAPPED Overlapped
);