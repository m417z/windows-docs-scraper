typedef struct _RESTOREPTINFOA {
  DWORD dwEventType;
  DWORD dwRestorePtType;
  INT64 llSequenceNumber;
  CHAR  szDescription[MAX_DESC];
} RESTOREPOINTINFOA, *PRESTOREPOINTINFOA;