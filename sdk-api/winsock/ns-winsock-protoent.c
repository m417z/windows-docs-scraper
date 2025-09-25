typedef struct protoent {
  char  *p_name;
  char  **p_aliases;
  short p_proto;
} PROTOENT, *PPROTOENT, *LPPROTOENT;