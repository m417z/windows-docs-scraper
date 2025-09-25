HRESULT OnSetTaskTime(
  [in] BSTR      szTargetName,
  [in] FILETIME  TaskStartTime,
  [in] FILETIME  TaskEndTime,
  [in] FILETIME  TaskDeadline,
  [in] BSTR      szTaskLabel,
  [in] BSTR      szTaskIdentifier,
  [in] BSTR      szTaskPlugin,
  [in] DWORD     dwTaskStatus,
  [in] SAFEARRAY *saContext
);