typedef struct {
  UCHAR                      Generation[4];
  UCHAR                      AdditionalLength[4];
  PRI_RESERVATION_DESCRIPTOR Reservations[0];
} PRI_RESERVATION_LIST, *PPRI_RESERVATION_LIST;