typedef struct _WWAN_UICC_ACCESS_BINARY {
  ULONG               Version;
  BYTE                AppId[WWAN_UICC_APP_ID_MAX_LEN];
  WWAN_UICC_FILE_PATH UiccFilePath;
  ULONG               FileOffset;
  ULONG               NumberOfBytes;
  BYTE                LocalPinSize;
  BYTE                LocalPin[WWAN_PIN_LEN];
  USHORT              BinaryDataSize;
  BYTE                BinaryData[ANYSIZE_ARRAY];
} WWAN_UICC_ACCESS_BINARY, *PWWAN_UICC_ACCESS_BINARY;