typedef struct _TC_GEN_FLOW {
  FLOWSPEC       SendingFlowspec;
  FLOWSPEC       ReceivingFlowspec;
  ULONG          TcObjectsLength;
  QOS_OBJECT_HDR TcObjects[1];
} TC_GEN_FLOW, *PTC_GEN_FLOW;