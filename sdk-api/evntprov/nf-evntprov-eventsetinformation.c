ULONG EVNTAPI EventSetInformation(
  [in] REGHANDLE        RegHandle,
  [in] EVENT_INFO_CLASS InformationClass,
  [in] PVOID            EventInformation,
  [in] ULONG            InformationLength
);