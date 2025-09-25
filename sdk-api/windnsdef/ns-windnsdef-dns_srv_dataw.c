typedef struct {
  PWSTR pNameTarget;
  WORD  wPriority;
  WORD  wWeight;
  WORD  wPort;
  WORD  Pad;
} DNS_SRV_DATAW, *PDNS_SRV_DATAW;