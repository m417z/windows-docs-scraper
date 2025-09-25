HRESULT OnQCReceive(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] ULONG64          QueueID,
  [in] REFGUID          guidMsgId,
  [in] REFGUID          guidWorkFlowId,
  [in] HRESULT          hr
);