typedef struct _BDA_WMDRM_KEYINFOLIST {
  PBDARESULT lResult;
  ULONG      ulKeyuuidBufferLen;
  GUID       argKeyuuidBuffer[MIN_DIMENSION];
} BDA_WMDRM_KEYINFOLIST, *PBDA_WMDRM_KEYINFOLIST;