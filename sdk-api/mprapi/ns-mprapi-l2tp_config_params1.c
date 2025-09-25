typedef struct _L2TP_CONFIG_PARAMS1 {
  DWORD                     dwNumPorts;
  DWORD                     dwPortFlags;
  DWORD                     dwTunnelConfigParamFlags;
  L2TP_TUNNEL_CONFIG_PARAMS TunnelConfigParams;
} L2TP_CONFIG_PARAMS1, *PL2TP_CONFIG_PARAMS1;