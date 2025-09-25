RPC_STATUS RpcMgmtEpEltInqBegin(
  RPC_BINDING_HANDLE EpBinding,
  unsigned long      InquiryType,
  RPC_IF_ID          *IfId,
  unsigned long      VersOption,
  UUID               *ObjectUuid,
  RPC_EP_INQ_HANDLE  *InquiryContext
);