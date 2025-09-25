typedef struct _IKEV2_CONFIG_PARAMS {
  DWORD                      dwNumPorts;
  DWORD                      dwPortFlags;
  DWORD                      dwTunnelConfigParamFlags;
  IKEV2_TUNNEL_CONFIG_PARAMS TunnelConfigParams;
} IKEV2_CONFIG_PARAMS, *PIKEV2_CONFIG_PARAMS;