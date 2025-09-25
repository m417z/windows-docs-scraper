HRESULT RtwqSetDeadline2(
  [in]      DWORD    workQueueId,
  [in]      LONGLONG deadlineInHNS,
  [in]      LONGLONG preDeadlineInHNS,
  [in, out] HANDLE   *pRequest
);