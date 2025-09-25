typedef struct _SUB_Q_HEADER {
  UCHAR Reserved;
  UCHAR AudioStatus;
  UCHAR DataLength[2];
} SUB_Q_HEADER, *PSUB_Q_HEADER;