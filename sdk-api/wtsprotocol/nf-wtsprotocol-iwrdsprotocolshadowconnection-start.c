HRESULT Start(
  [in] WCHAR                       *pTargetServerName,
  [in] DWORD                       TargetSessionId,
  [in] BYTE                        HotKeyVk,
  [in] USHORT                      HotkeyModifiers,
  [in] IWRdsProtocolShadowCallback *pShadowCallback
);