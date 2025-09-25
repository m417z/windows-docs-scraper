typedef struct {
  UCHAR ReservationKey[8];
  UCHAR ServiceActionReservationKey[8];
  UCHAR ScopeSpecificAddress[4];
  UCHAR ActivatePersistThroughPowerLoss : 1;
  UCHAR Reserved1 : 1;
  UCHAR AllTargetPorts : 1;
  UCHAR SpecifyInitiatorPorts : 1;
  UCHAR Reserved2 : 4;
  UCHAR Reserved3;
  UCHAR Obsolete[2];
} PRO_PARAMETER_LIST, *PPRO_PARAMETER_LIST;