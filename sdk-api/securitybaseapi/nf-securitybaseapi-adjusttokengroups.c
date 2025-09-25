BOOL AdjustTokenGroups(
  [in]            HANDLE        TokenHandle,
  [in]            BOOL          ResetToDefault,
  [in, optional]  PTOKEN_GROUPS NewState,
  [in]            DWORD         BufferLength,
  [out, optional] PTOKEN_GROUPS PreviousState,
  [out, optional] PDWORD        ReturnLength
);