typedef struct _SCO_INDICATION_PARAMETERS {
  SCO_CHANNEL_HANDLE ConnectionHandle;
  BTH_ADDR           BtAddress;
  union {
    struct {
      struct {
        SCO_LINK_TYPE LinkType;
      } Request;
    } Connect;
    struct {
      SCO_DISCONNECT_REASON Reason;
      BOOLEAN               CloseNow;
    } Disconnect;
  } Parameters;
} SCO_INDICATION_PARAMETERS, *PSCO_INDICATION_PARAMETERS;