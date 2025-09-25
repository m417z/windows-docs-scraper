typedef struct _QualityOfService {
  FLOWSPEC SendingFlowspec;
  FLOWSPEC ReceivingFlowspec;
  WSABUF   ProviderSpecific;
} QOS, *LPQOS;