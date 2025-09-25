NTSTATUS IPsecSaContextCreate1(
  [in]            HANDLE                              engineHandle,
  [in]            const IPSEC_TRAFFIC1                *outboundTraffic,
  [in, optional]  const IPSEC_VIRTUAL_IF_TUNNEL_INFO0 *virtualIfTunnelInfo,
  [out, optional] UINT64                              *inboundFilterId,
  [out]           UINT64                              *id
);