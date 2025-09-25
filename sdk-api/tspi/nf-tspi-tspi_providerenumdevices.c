LONG TSPIAPI TSPI_providerEnumDevices(
  DWORD      dwPermanentProviderID,
  LPDWORD    lpdwNumLines,
  LPDWORD    lpdwNumPhones,
  HPROVIDER  hProvider,
  LINEEVENT  lpfnLineCreateProc,
  PHONEEVENT lpfnPhoneCreateProc
);