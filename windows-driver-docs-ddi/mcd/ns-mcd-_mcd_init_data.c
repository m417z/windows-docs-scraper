typedef struct _MCD_INIT_DATA {
  ULONG                       InitDataSize;
  CHANGER_EXTENSION_SIZE      ChangerAdditionalExtensionSize;
  CHANGER_INITIALIZE          ChangerInitialize;
  CHANGER_ERROR_ROUTINE       ChangerError;
  CHANGER_PERFORM_DIAGNOSTICS ChangerPerformDiagnostics;
  CHANGER_COMMAND_ROUTINE     ChangerGetParameters;
  CHANGER_COMMAND_ROUTINE     ChangerGetStatus;
  CHANGER_COMMAND_ROUTINE     ChangerGetProductData;
  CHANGER_COMMAND_ROUTINE     ChangerSetAccess;
  CHANGER_COMMAND_ROUTINE     ChangerGetElementStatus;
  CHANGER_COMMAND_ROUTINE     ChangerInitializeElementStatus;
  CHANGER_COMMAND_ROUTINE     ChangerSetPosition;
  CHANGER_COMMAND_ROUTINE     ChangerExchangeMedium;
  CHANGER_COMMAND_ROUTINE     ChangerMoveMedium;
  CHANGER_COMMAND_ROUTINE     ChangerReinitializeUnit;
  CHANGER_COMMAND_ROUTINE     ChangerQueryVolumeTags;
} MCD_INIT_DATA, *PMCD_INIT_DATA;