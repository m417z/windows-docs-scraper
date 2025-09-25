HRESULT RegisterWaitHandleCallback(
  [in]  HANDLE                           handle,
  [in]  IDirectManipulationUpdateHandler *eventHandler,
  [out] DWORD                            *cookie
);