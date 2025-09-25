typedef struct _POWERSOURCESTATUS {
  POWERSOURCEID PowerSourceId;
  ULONG         MaxChargeCurrent;
  ULONG         PowerSourceInformation;
  BOOLEAN       PowerSourceStatus;
} POWERSOURCESTATUS, *PPOWERSOURCESTATUS;