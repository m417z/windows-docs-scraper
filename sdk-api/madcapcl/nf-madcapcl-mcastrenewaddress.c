DWORD McastRenewAddress(
  [in]      IP_ADDR_FAMILY        AddrFamily,
  [in]      LPMCAST_CLIENT_UID    pRequestID,
  [in]      PMCAST_LEASE_REQUEST  pRenewRequest,
  [in, out] PMCAST_LEASE_RESPONSE pRenewResponse
);