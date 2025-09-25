HRESULT DrtCreateIpv6UdpTransport(
            DRT_SCOPE      scope,
            ULONG          dwScopeId,
            ULONG          dwLocalityThreshold,
  [in, out] USHORT         *pwPort,
  [out]     HDRT_TRANSPORT *phTransport
);