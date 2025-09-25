DWORD McastRequestAddress(
  [in]      IP_ADDR_FAMILY        AddrFamily,
  [in]      LPMCAST_CLIENT_UID    pRequestID,
  [in]      PMCAST_SCOPE_CTX      pScopeCtx,
  [in]      PMCAST_LEASE_REQUEST  pAddrRequest,
  [in, out] PMCAST_LEASE_RESPONSE pAddrResponse
);