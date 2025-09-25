typedef struct servent {
  char  *s_name;
  char  **s_aliases;
#if ...
  char  *s_proto;
#if ...
  short s_port;
#else
  short s_port;
#endif
#else
  char  *s_proto;
#endif
} SERVENT, *PSERVENT, *LPSERVENT;