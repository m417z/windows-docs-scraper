HRESULT WinBioRegisterEventMonitor(
  [in] WINBIO_SESSION_HANDLE  SessionHandle,
  [in] WINBIO_EVENT_TYPE      EventMask,
  [in] PWINBIO_EVENT_CALLBACK EventCallback,
  [in] PVOID                  EventCallbackContext
);