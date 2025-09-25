typedef struct {
  LONGLONG        PresentationStart;
  LONGLONG        Duration;
  KSPIN_INTERFACE Interface;
  LONG            Rate;
  ULONG           Flags;
} KSRATE, *PKSRATE;