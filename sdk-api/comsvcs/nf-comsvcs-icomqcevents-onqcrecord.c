HRESULT OnQCRecord(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] ULONG64          objid,
  [in] WCHAR [60]       szQueue,
  [in] REFGUID          guidMsgId,
  [in] REFGUID          guidWorkFlowId,
  [in] HRESULT          msmqhr
);