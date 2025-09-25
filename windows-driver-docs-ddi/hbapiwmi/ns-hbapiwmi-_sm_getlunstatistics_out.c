typedef struct _SM_GetLUNStatistics_OUT {
  ULONG                       HBAStatus;
  MS_SMHBA_PROTOCOLSTATISTICS ProtocolStatistics;
} SM_GetLUNStatistics_OUT, *PSM_GetLUNStatistics_OUT;