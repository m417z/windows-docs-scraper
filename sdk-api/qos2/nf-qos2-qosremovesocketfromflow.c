ExternC BOOL QOSRemoveSocketFromFlow(
  [in]           HANDLE     QOSHandle,
  [in, optional] SOCKET     Socket,
  [in]           QOS_FLOWID FlowId,
                 DWORD      Flags
);