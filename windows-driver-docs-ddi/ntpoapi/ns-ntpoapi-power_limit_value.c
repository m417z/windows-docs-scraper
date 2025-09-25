typedef struct _POWER_LIMIT_VALUE {
  POWER_LIMIT_TYPES Type;
  ULONG             DomainId;
  ULONG             TargetValue;
  ULONG             TimeParameter;
} POWER_LIMIT_VALUE, *PPOWER_LIMIT_VALUE;