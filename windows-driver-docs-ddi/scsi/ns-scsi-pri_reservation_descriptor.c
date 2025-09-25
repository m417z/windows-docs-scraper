typedef struct {
  UCHAR ReservationKey[8];
  UCHAR ScopeSpecificAddress[4];
  UCHAR Reserved;
  UCHAR Type : 4;
  UCHAR Scope : 4;
  UCHAR Obsolete[2];
} PRI_RESERVATION_DESCRIPTOR, *PPRI_RESERVATION_DESCRIPTOR;