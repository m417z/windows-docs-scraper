void NET_PACKET_QUEUE_CONFIG_INIT(
  [_Out_] NET_PACKET_QUEUE_CONFIG                   *Config,
  [_In_]  PFN_PACKET_QUEUE_ADVANCE                  EvtAdvance,
  [_In_]  PFN_PACKET_QUEUE_SET_NOTIFICATION_ENABLED EvtSetNotificationEnabled,
  [_In_]  PFN_PACKET_QUEUE_CANCEL                   EvtCancel
);