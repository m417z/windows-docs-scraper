typedef struct _WSK_BUF_LIST {
  struct _WSK_BUF_LIST *Next;
  WSK_BUF              Buffer;
} WSK_BUF_LIST, *PWSK_BUF_LIST;