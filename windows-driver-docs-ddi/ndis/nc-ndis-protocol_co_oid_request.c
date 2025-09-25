PROTOCOL_CO_OID_REQUEST ProtocolCoOidRequest;

NDIS_STATUS ProtocolCoOidRequest(
  [in]      NDIS_HANDLE ProtocolAfContext,
  [in]      NDIS_HANDLE ProtocolVcContext,
  [in]      NDIS_HANDLE ProtocolPartyContext,
  [in, out] PNDIS_OID_REQUEST OidRequest
)
{...}