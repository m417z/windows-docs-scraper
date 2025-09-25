typedef struct _WWAN_UICC_FILE_STATUS {
  ULONG                        Version;
  ULONG                        StatusWord1;
  ULONG                        StatusWord2;
  WWAN_UICC_FILE_ACCESSIBILITY FileAccessibility;
  WWAN_UICC_FILE_TYPE          FileType;
  WWAN_UICC_FILE_STRUCTURE     FileStructure;
  ULONG                        ItemCount;
  ULONG                        ItemSize;
  WWAN_PIN_TYPE                FileLockStatus[WWAN_EF_ACCESS_TYPES_LEN];
} WWAN_UICC_FILE_STATUS, *PWWAN_UICC_FILE_STATUS;