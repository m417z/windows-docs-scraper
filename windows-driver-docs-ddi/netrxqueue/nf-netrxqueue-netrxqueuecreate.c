NTSTATUS NetRxQueueCreate(
  [_Inout_]  NETRXQUEUE_INIT         *NetRxQueueInit,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES   *RxQueueAttributes,
  [_In_]     NET_PACKET_QUEUE_CONFIG *Configuration,
  [_Out_]    NETPACKETQUEUE          *PacketQueue
);