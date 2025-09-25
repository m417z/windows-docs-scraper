HRESULT WinBioAsyncOpenSession(
  [in]            WINBIO_BIOMETRIC_TYPE             Factor,
  [in]            WINBIO_POOL_TYPE                  PoolType,
  [in]            WINBIO_SESSION_FLAGS              Flags,
  [in, optional]  WINBIO_UNIT_ID                    *UnitArray,
  [in, optional]  SIZE_T                            UnitCount,
  [in, optional]  GUID                              *DatabaseId,
  [in]            WINBIO_ASYNC_NOTIFICATION_METHOD  NotificationMethod,
  [in, optional]  HWND                              TargetWindow,
  [in, optional]  UINT                              MessageCode,
  [in, optional]  PWINBIO_ASYNC_COMPLETION_CALLBACK CallbackRoutine,
  [in, optional]  PVOID                             UserData,
  [in]            BOOL                              AsynchronousOpen,
  [out, optional] WINBIO_SESSION_HANDLE             *SessionHandle
);