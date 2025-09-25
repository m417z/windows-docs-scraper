HRESULT QueryProperty(
  [in]            GUID                QueryType,
  [in]            ULONG               ulNumEntriesIn,
  [in]            ULONG               ulNumEntriesOut,
  [in, optional]  PWTS_PROPERTY_VALUE pPropertyEntriesIn,
  [out, optional] PWTS_PROPERTY_VALUE pPropertyEntriesOut
);