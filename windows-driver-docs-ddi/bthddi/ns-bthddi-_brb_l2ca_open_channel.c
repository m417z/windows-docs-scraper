struct _BRB_L2CA_OPEN_CHANNEL {
  BRB_HEADER                     Hdr;
  L2CAP_CHANNEL_HANDLE           ChannelHandle;
  union {
    struct {
      USHORT Response;
      USHORT ResponseStatus;
    };
    USHORT Psm;
  };
  ULONG                          ChannelFlags;
  BTH_ADDR                       BtAddress;
  struct {
    ULONG                    Flags;
    L2CAP_CONFIG_VALUE_RANGE Mtu;
    L2CAP_CONFIG_VALUE_RANGE FlushTO;
    L2CAP_FLOWSPEC           Flow;
    USHORT                   LinkTO;
    ULONG                    NumExtraOptions;
    PL2CAP_CONFIG_OPTION     ExtraOptions;
    struct {
      UCHAR ServiceType;
      ULONG Latency;
    } LocalQos;
  } ConfigOut;
  struct {
    ULONG                    Flags;
    L2CAP_CONFIG_VALUE_RANGE Mtu;
    L2CAP_CONFIG_RANGE       FlushTO;
  } ConfigIn;
  ULONG                          CallbackFlags;
  PFNBTHPORT_INDICATION_CALLBACK Callback;
  PVOID                          CallbackContext;
  PVOID                          ReferenceObject;
  CHANNEL_CONFIG_RESULTS         OutResults;
  CHANNEL_CONFIG_RESULTS         InResults;
  UCHAR                          IncomingQueueDepth;
};