typedef struct _VIDEO_WIN32K_CALLBACKS_PARAMS {
  VIDEO_WIN32K_CALLBACKS_PARAMS_TYPE CalloutType;
  PVOID                              PhysDisp;
  ULONG_PTR                          Param;
  LONG                               Status;
  BOOLEAN                            LockUserSession;
  BOOLEAN                            IsPostDevice;
  BOOLEAN                            SurpriseRemoval;
  BOOLEAN                            WaitForQueueReady;
} VIDEO_WIN32K_CALLBACKS_PARAMS, *PVIDEO_WIN32K_CALLBACKS_PARAMS;