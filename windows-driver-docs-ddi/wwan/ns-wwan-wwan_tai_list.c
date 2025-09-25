typedef struct _WWAN_TAI_LIST {
  WWAN_STRUCT_TYPE TaiListType;
  BYTE             DataBuffer[ANYSIZE_ARRAY];
} WWAN_TAI_LIST, *PWWAN_TAI_LIST;