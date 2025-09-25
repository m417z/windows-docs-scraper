typedef struct _INDICATION_PARAMETERS {
  L2CAP_CHANNEL_HANDLE ConnectionHandle;
  IN BTH_ADDR          BtAddress;
  union {
    struct {
      struct {
        OUT USHORT PSM;
      } Request;
    } Connect;
    struct {
      CHANNEL_CONFIG_PARAMETERS CurrentParams;
      CHANNEL_CONFIG_PARAMETERS RequestedParams;
      CHANNEL_CONFIG_PARAMETERS ResponseParams;
      USHORT                    Response;
    } ConfigRequest;
    struct {
      CHANNEL_CONFIG_PARAMETERS CurrentParams;
      CHANNEL_CONFIG_PARAMETERS RequestedParams;
      CHANNEL_CONFIG_PARAMETERS RejectedParams;
      PCO_TYPE                  UnknownTypes;
      ULONG                     NumUnknownTypes;
      CHANNEL_CONFIG_PARAMETERS NewRequestParams;
      USHORT                    Response;
    } ConfigResponse;
    struct {
      ULONG                NumExtraOptions;
      PL2CAP_CONFIG_OPTION ExtraOptions;
    } FreeExtraOptions;
    struct {
      L2CAP_DISCONNECT_REASON Reason;
      BOOLEAN                 CloseNow;
    } Disconnect;
    struct {
      ULONG PacketLength;
      ULONG TotalQueueLength;
    } RecvPacket;
  } Parameters;
} *PINDICATION_PARAMETERS, INDICATION_PARAMETERS;