typedef enum _WWAN_AUTH_PROTOCOL {
  WwanAuthProtocolNone,
  WwanAuthProtocolPap,
  WwanAuthProtocolChap,
  WwanAuthProtocolMsChapV2,
  WwanAuthProtocolAuto,
  WwanAuthProtocolMax
} WWAN_AUTH_PROTOCOL, *PWWAN_AUTH_PROTOCOL;