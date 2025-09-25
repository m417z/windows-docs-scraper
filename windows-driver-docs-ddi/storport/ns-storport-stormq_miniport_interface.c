typedef struct _STORMQ_MINIPORT_INTERFACE {
  ULONG                                      Size;
  USHORT                                     StorMQVersion;
  USHORT                                     MiniportVersion;
  struct {
    ULONGLONG ProvideVirtualAddresses : 1;
    ULONGLONG Reserved : 63;
  } Flags;
  PHW_STORMQ_COMPLETION_NOTIFY_WITH_CALLBACK HwStorMQCompletionNotifyWithCallback;
  PHW_STORMQ_QUERY_PROPERTY                  HwStorMQQueryProperty;
  PHW_STORMQ_SET_PROPERTY                    HwStorMQSetProperty;
  PHW_STORMQ_START_SRB                       HwStorMQStartSrb;
} STORMQ_MINIPORT_INTERFACE, *PSTORMQ_MINIPORT_INTERFACE;