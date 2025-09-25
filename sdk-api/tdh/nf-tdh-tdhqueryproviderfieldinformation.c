TDHSTATUS TdhQueryProviderFieldInformation(
  [in]      LPGUID                    pGuid,
  [in]      ULONGLONG                 EventFieldValue,
  [in]      EVENT_FIELD_TYPE          EventFieldType,
  [out]     PPROVIDER_FIELD_INFOARRAY pBuffer,
  [in, out] ULONG                     *pBufferSize
);