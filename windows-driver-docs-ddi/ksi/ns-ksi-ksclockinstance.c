typedef struct {
  KSOBJECT_HEADER  Header;
  PKSIDEFAULTCLOCK DefaultClock;
  ULONG            Reserved;
} KSCLOCKINSTANCE, *PKSCLOCKINSTANCE;