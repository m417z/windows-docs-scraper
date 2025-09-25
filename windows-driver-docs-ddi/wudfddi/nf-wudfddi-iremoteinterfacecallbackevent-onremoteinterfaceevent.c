void OnRemoteInterfaceEvent(
  [in]           IWDFRemoteInterface *pWdfRemoteInterface,
  [in]           REFGUID             EventGuid,
  [in, optional] BYTE                *pbData,
  [in]           DWORD               cbDataSize,
  [in]           DWORD               NameBufferOffset
);