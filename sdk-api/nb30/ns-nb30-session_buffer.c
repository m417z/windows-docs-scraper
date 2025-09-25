typedef struct _SESSION_BUFFER {
  UCHAR lsn;
  UCHAR state;
  UCHAR local_name[NCBNAMSZ];
  UCHAR remote_name[NCBNAMSZ];
  UCHAR rcvs_outstanding;
  UCHAR sends_outstanding;
} SESSION_BUFFER, *PSESSION_BUFFER;