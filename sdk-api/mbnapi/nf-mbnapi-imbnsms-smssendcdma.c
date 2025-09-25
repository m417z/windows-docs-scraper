HRESULT SmsSendCdma(
  [in]  LPCWSTR               address,
  [in]  MBN_SMS_CDMA_ENCODING encoding,
  [in]  MBN_SMS_CDMA_LANG     language,
  [in]  ULONG                 sizeInCharacters,
  [in]  SAFEARRAY             *message,
  [out] ULONG                 *requestID
);