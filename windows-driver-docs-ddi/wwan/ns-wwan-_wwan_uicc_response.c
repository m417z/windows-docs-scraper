typedef struct _WWAN_UICC_RESPONSE {
  ULONG  Version;
  ULONG  StatusWord1;
  ULONG  StatusWord2;
  USHORT ResponseDataSize;
  BYTE   ResponseData[ANYSIZE_ARRAY];
} WWAN_UICC_RESPONSE, *PWWAN_UICC_RESPONSE;