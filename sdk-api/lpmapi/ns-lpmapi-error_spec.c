typedef struct {
  RsvpObjHdr errs_header;
  union {
    Error_Spec_IPv4 errs_ipv4;
  } errs_u;
} ERROR_SPEC;