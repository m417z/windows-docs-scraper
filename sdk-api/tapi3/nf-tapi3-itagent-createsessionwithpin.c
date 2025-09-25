HRESULT CreateSessionWithPIN(
  [in]  ITACDGroup     *pACDGroup,
  [in]  ITAddress      *pAddress,
  [in]  BSTR           pPIN,
  [out] ITAgentSession **ppAgentSession
);