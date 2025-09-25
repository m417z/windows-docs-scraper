typedef struct lpminitinfo {
  DWORD            PcmVersionNumber;
  DWORD            ResultTimeLimit;
  int              ConfiguredLpmCount;
  PALLOCMEM        AllocMemory;
  PFREEMEM         FreeMemory;
  CBADMITRESULT    PcmAdmitResultCallback;
  CBGETRSVPOBJECTS GetRsvpObjectsCallback;
} LPM_INIT_INFO;