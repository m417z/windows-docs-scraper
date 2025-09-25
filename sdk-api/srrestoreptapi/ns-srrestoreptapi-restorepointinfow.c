typedef struct _RESTOREPTINFOW {
  DWORD dwEventType;
  DWORD dwRestorePtType;
  INT64 llSequenceNumber;
  WCHAR szDescription[MAX_DESC_W];
} RESTOREPOINTINFOW, *PRESTOREPOINTINFOW;