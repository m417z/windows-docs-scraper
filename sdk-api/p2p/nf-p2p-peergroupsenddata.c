NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGroupSendData(
  [in] HGROUP     hGroup,
  [in] ULONGLONG  ullConnectionId,
  [in] const GUID *pType,
  [in] ULONG      cbData,
  [in] PVOID      pvData
);