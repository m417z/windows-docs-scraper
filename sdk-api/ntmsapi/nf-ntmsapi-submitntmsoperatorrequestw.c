DWORD SubmitNtmsOperatorRequestW(
  [in]  HANDLE      hSession,
  [in]  DWORD       dwRequest,
  [in]  LPCWSTR     lpMessage,
  [in]  LPNTMS_GUID lpArg1Id,
  [in]  LPNTMS_GUID lpArg2Id,
  [out] LPNTMS_GUID lpRequestId
);