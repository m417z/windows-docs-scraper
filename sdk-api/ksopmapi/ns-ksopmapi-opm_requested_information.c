typedef struct _OPM_REQUESTED_INFORMATION {
  OPM_OMAC omac;
  ULONG    cbRequestedInformationSize;
  BYTE     abRequestedInformation[OPM_REQUESTED_INFORMATION_SIZE];
} OPM_REQUESTED_INFORMATION;