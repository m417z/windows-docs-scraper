typedef struct _CHANNEL_CONFIG_PARAMETERS {
  ULONG                Flags;
  CO_MTU               Mtu;
  CO_FLUSHTO           FlushTO;
  ULONG                NumExtraOptions;
  PL2CAP_CONFIG_OPTION ExtraOptions;
  L2CAP_FLOWSPEC       Flow;
} CHANNEL_CONFIG_PARAMETERS, *PCHANNEL_CONFIG_PARAMETERS;