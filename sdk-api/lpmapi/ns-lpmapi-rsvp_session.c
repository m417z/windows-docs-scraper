typedef struct {
  RsvpObjHdr sess_header;
  union {
    Session_IPv4 sess_ipv4;
  } sess_u;
} RSVP_SESSION;