typedef struct {
  RsvpObjHdr filt_header;
  union {
    Filter_Spec_IPv4    filt_ipv4;
    Filter_Spec_IPv4GPI filt_ipv4gpi;
  } filt_u;
} FILTER_SPEC;