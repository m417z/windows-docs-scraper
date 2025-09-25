LONG TSPIAPI TSPI_providerInit(
  DWORD            dwTSPIVersion,
  DWORD            dwPermanentProviderID,
  DWORD            dwLineDeviceIDBase,
  DWORD            dwPhoneDeviceIDBase,
  DWORD_PTR        dwNumLines,
  DWORD_PTR        dwNumPhones,
  ASYNC_COMPLETION lpfnCompletionProc,
  LPDWORD          lpdwTSPIOptions
);