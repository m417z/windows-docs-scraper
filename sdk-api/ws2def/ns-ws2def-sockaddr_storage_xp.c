typedef struct sockaddr_storage_xp {
  short   ss_family;
  CHAR    __ss_pad1[_SS_PAD1SIZE];
  __int64 __ss_align;
  CHAR    __ss_pad2[_SS_PAD2SIZE];
} SOCKADDR_STORAGE_XP, *PSOCKADDR_STORAGE_XP, *LPSOCKADDR_STORAGE_XP;