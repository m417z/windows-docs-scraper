typedef struct _POWER_LIMIT_ATTRIBUTES {
  POWER_LIMIT_TYPES Type;
  ULONG             DomainId;
  ULONG             MaxValue;
  ULONG             MinValue;
  ULONG             MinTimeParameter;
  ULONG             MaxTimeParameter;
  ULONG             DefaultACValue;
  ULONG             DefaultDCValue;
  union {
    struct {
      ULONG SupportTimeParameter : 1;
      ULONG Reserved : 31;
    };
    ULONG AsUlong;
  } Flags;
} POWER_LIMIT_ATTRIBUTES, *PPOWER_LIMIT_ATTRIBUTES;