typedef struct _WWAN_UICC_ACCESS_RECORD {
  ULONG               Version;
  BYTE                AppId[WWAN_UICC_APP_ID_MAX_LEN];
  WWAN_UICC_FILE_PATH UiccFilePath;
  ULONG               RecordNumber;
  BYTE                LocalPinSize;
  BYTE                LocalPin[WWAN_PIN_LEN];
  BYTE                RecordDataSize;
  BYTE                RecordData[WWAN_UICC_RECORD_DATA_MAX_LEN];
} WWAN_UICC_ACCESS_RECORD, *PWWAN_UICC_ACCESS_RECORD;