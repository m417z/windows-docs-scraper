typedef struct _INDICATION_PARAMETERS_ENHANCED {
  L2CAP_CHANNEL_HANDLE ConnectionHandle;
  IN BTH_ADDR          BtAddress;
  union {
    struct {
      struct {
        OUT USHORT PSM;
      } Request;
    } Connect;
    struct {
      CHANNEL_CONFIG_PARAMETERS_ENHANCED CurrentParams;
      CHANNEL_CONFIG_PARAMETERS_ENHANCED RequestedParams;
      CHANNEL_CONFIG_PARAMETERS_ENHANCED ResponseParams;
      USHORT                             Response;
    } ConfigRequest;
    struct {
      CHANNEL_CONFIG_PARAMETERS_ENHANCED CurrentParams;
      CHANNEL_CONFIG_PARAMETERS_ENHANCED RequestedParams;
      CHANNEL_CONFIG_PARAMETERS_ENHANCED RejectedParams;
      PCO_TYPE                           UnknownTypes;
      ULONG                              NumUnknownTypes;
      CHANNEL_CONFIG_PARAMETERS_ENHANCED NewRequestParams;
      USHORT                             Response;
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
    PVOID Reserved;
  } Parameters;
} *PINDICATION_PARAMETERS_ENHANCED, INDICATION_PARAMETERS_ENHANCED;