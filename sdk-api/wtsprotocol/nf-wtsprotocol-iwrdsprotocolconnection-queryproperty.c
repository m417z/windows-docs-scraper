HRESULT QueryProperty(
  [in]            GUID                 QueryType,
  [in]            ULONG                ulNumEntriesIn,
  [in]            ULONG                ulNumEntriesOut,
  [in, optional]  PWRDS_PROPERTY_VALUE pPropertyEntriesIn,
  [out, optional] PWRDS_PROPERTY_VALUE pPropertyEntriesOut
);