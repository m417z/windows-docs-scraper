typedef struct _BDA_WMDRM_RENEWLICENSE {
  PBDARESULT lResult;
  ULONG      ulDescrambleStatus;
  ULONG      ulXmrLicenseOutputLength;
  BYTE       argbXmrLicenceOutputBuffer[MIN_DIMENSION];
} BDA_WMDRM_RENEWLICENSE, *PBDA_WMDRM_RENEWLICENSE;