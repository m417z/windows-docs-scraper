typedef struct _WSMAN_AUTHZ_QUOTA {
  DWORD maxAllowedConcurrentShells;
  DWORD maxAllowedConcurrentOperations;
  DWORD timeslotSize;
  DWORD maxAllowedOperationsPerTimeslot;
} WSMAN_AUTHZ_QUOTA;