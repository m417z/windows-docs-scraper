typedef struct ldap {
  struct {
    UINT_PTR  sb_sd;
    UCHAR     *Reserved1[(10  sizeof(ULONG))+ 1];
    ULONG_PTR sb_naddr;
    UCHAR     *Reserved2[(6  sizeof(ULONG))];
  } ld_sb;
  PCHAR  ld_host;
  ULONG  ld_version;
  UCHAR  ld_lberoptions;
  ULONG  ld_deref;
  ULONG  ld_timelimit;
  ULONG  ld_sizelimit;
  ULONG  ld_errno;
  PCHAR  ld_matched;
  PCHAR  ld_error;
  ULONG  ld_msgid;
  UCHAR  *Reserved3[(6  sizeof(ULONG))+ 1];
  ULONG  ld_cldaptries;
  ULONG  ld_cldaptimeout;
  ULONG  ld_refhoplimit;
  ULONG  ld_options;
  ULONG  ld_maxvalrange;
} LDAP, *PLDAP;