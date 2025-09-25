NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGraphSendData(
  [in] HGRAPH     hGraph,
  [in] ULONGLONG  ullConnectionId,
  [in] const GUID *pType,
  [in] ULONG      cbData,
  [in] PVOID      pvData
);