DWORD IPsecSaContextCreate0(
  [in]            HANDLE               engineHandle,
  [in]            const IPSEC_TRAFFIC0 *outboundTraffic,
  [out, optional] UINT64               *inboundFilterId,
  [out]           UINT64               *id
);