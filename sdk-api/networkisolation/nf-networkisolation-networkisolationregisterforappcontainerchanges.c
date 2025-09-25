DWORD NetworkIsolationRegisterForAppContainerChanges(
  [in]           DWORD                   flags,
  [in]           PAC_CHANGES_CALLBACK_FN callback,
  [in, optional] PVOID                   context,
  [out]          HANDLE                  *registrationObject
);