typedef struct _POWERSOURCEUPDATE {
  POWERSOURCEID PowerSourceId;
  ULONG         MaxChargeCurrent;
  BOOLEAN       PowerSourceAvailableStatus;
  PVOID         PowerSourceInformation;
} POWERSOURCEUPDATE, *PPOWERSOURCEUPDATE;