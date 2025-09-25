typedef struct {
  RsvpObjHdr hop_header;
  union {
    Rsvp_Hop_IPv4 hop_ipv4;
  } hop_u;
} RSVP_HOP;