typedef struct _NET_PACKET_QUEUE_CONFIG {
  ULONG                                     Size;
  PFN_PACKET_QUEUE_START                    EvtStart;
  PFN_PACKET_QUEUE_STOP                     EvtStop;
  PFN_PACKET_QUEUE_ADVANCE                  EvtAdvance;
  PFN_PACKET_QUEUE_SET_NOTIFICATION_ENABLED EvtSetNotificationEnabled;
  PFN_PACKET_QUEUE_CANCEL                   EvtCancel;
  NETEXECUTIONCONTEXT                       ExecutionContext;
} NET_PACKET_QUEUE_CONFIG;