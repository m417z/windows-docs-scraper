BOOL WTSStartRemoteControlSessionW(
  [in] LPWSTR pTargetServerName,
  [in] ULONG  TargetLogonId,
  [in] BYTE   HotkeyVk,
  [in] USHORT HotkeyModifiers
);