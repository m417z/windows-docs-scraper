PROTOCOL_CO_OID_REQUEST_COMPLETE ProtocolCoOidRequestComplete;

VOID ProtocolCoOidRequestComplete(
  [in]      NDIS_HANDLE ProtocolAfContext,
  [in]      NDIS_HANDLE ProtocolVcContext,
  [in]      NDIS_HANDLE ProtocolPartyContext,
  [in, out] PNDIS_OID_REQUEST OidRequest,
  [in]      NDIS_STATUS Status
)
{...}