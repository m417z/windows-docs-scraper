HRESULT PostEvent(
  [in] REFGUID        EventGuid,
  [in] WDF_EVENT_TYPE EventType,
  [in] BYTE           *pbData,
  [in] DWORD          cbDataSize
);