typedef struct _RSVP_POLICY {
  USHORT Len;
  USHORT Type;
  UCHAR  Info[4];
} RSVP_POLICY, *LPRSVP_POLICY;