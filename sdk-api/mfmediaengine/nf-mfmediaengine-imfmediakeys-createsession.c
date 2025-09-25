HRESULT CreateSession(
  BSTR                     mimeType,
  const BYTE               *initData,
  DWORD                    cb,
  const BYTE               *customData,
  DWORD                    cbCustomData,
  IMFMediaKeySessionNotify *notify,
  IMFMediaKeySession       **ppSession
);