typedef struct {
  RsvpObjHdr scopl_header;
  union {
    Scope_list_ipv4 scopl_ipv4;
  } scope_u;
} RSVP_SCOPE;