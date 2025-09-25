typedef struct _NCB {
  UCHAR  ncb_command;
  UCHAR  ncb_retcode;
  UCHAR  ncb_lsn;
  UCHAR  ncb_num;
  PUCHAR ncb_buffer;
  WORD   ncb_length;
  UCHAR  ncb_callname[NCBNAMSZ];
  UCHAR  ncb_name[NCBNAMSZ];
  UCHAR  ncb_rto;
  UCHAR  ncb_sto;
  void()(_NCB *)  * ncb_post;
  UCHAR  ncb_lana_num;
  UCHAR  ncb_cmd_cplt;
#if ...
  UCHAR  ncb_reserve[18];
#else
  UCHAR  ncb_reserve[10];
#endif
  HANDLE ncb_event;
} NCB, *PNCB;