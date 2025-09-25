TDHSTATUS TdhEnumerateProviderFieldInformation(
  [in]            LPGUID                    pGuid,
  [in]            EVENT_FIELD_TYPE          EventFieldType,
  [out, optional] PPROVIDER_FIELD_INFOARRAY pBuffer,
  [in, out]       ULONG                     *pBufferSize
);