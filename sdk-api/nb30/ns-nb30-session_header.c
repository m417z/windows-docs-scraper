typedef struct _SESSION_HEADER {
  UCHAR sess_name;
  UCHAR num_sess;
  UCHAR rcv_dg_outstanding;
  UCHAR rcv_any_outstanding;
} SESSION_HEADER, *PSESSION_HEADER;