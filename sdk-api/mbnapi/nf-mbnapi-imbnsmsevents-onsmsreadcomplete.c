HRESULT OnSmsReadComplete(
  [in] IMbnSms        *sms,
  [in] MBN_SMS_FORMAT smsFormat,
  [in] SAFEARRAY      *readMsgs,
  [in] VARIANT_BOOL   moreMsgs,
  [in] ULONG          requestID,
  [in] HRESULT        status
);