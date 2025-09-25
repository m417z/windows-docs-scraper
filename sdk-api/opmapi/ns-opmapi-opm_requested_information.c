typedef struct _OPM_REQUESTED_INFORMATION {
  OPM_OMAC omac;
  ULONG    cbRequestedInformationSize;
  BYTE     abRequestedInformation[4076];
} OPM_REQUESTED_INFORMATION;