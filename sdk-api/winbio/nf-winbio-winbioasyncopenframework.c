HRESULT WinBioAsyncOpenFramework(
  [in]           WINBIO_ASYNC_NOTIFICATION_METHOD  NotificationMethod,
  [in, optional] HWND                              TargetWindow,
  [in, optional] UINT                              MessageCode,
  [in, optional] PWINBIO_ASYNC_COMPLETION_CALLBACK CallbackRoutine,
  [in, optional] PVOID                             UserData,
  [in]           BOOL                              AsynchronousOpen,
  [out]          WINBIO_FRAMEWORK_HANDLE           *FrameworkHandle
);