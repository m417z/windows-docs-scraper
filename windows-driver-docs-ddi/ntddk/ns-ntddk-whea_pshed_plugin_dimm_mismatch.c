typedef struct _WHEA_PSHED_PLUGIN_DIMM_MISMATCH {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  UINT16               FirmwareBank;
  UINT16               FirmwareCol;
  UINT16               FirmwareRow;
  UINT16               RetryRdBank;
  UINT16               RetryRdCol;
  UINT16               RetryRdRow;
  UINT16               TaBank;
  UINT16               TaCol;
  UINT16               TaRow;
} WHEA_PSHED_PLUGIN_DIMM_MISMATCH, *PWHEA_PSHED_PLUGIN_DIMM_MISMATCH;