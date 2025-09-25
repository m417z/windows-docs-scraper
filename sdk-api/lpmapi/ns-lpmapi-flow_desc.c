typedef struct flow_desc {
  union {
    SENDER_TSPEC *stspec;
    IS_FLOWSPEC  *isflow;
  } u1;
  union {
    SENDER_TEMPLATE *stemp;
    FILTER_SPEC     *fspec;
  } u2;
} FLOW_DESC;