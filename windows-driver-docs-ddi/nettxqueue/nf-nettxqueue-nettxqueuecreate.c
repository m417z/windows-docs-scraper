NTSTATUS NetTxQueueCreate(
  [_Inout_]  NETTXQUEUE_INIT         *NetTxQueueInit,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES   *TxQueueAttributes,
  [_In_]     NET_PACKET_QUEUE_CONFIG *Configuration,
  [_Out_]    NETPACKETQUEUE          *PacketQueue
);