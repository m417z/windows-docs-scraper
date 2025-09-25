typedef struct ldapvlvinfo {
  int     ldvlv_version;
  ULONG   ldvlv_before_count;
  ULONG   ldvlv_after_count;
  ULONG   ldvlv_offset;
  ULONG   ldvlv_count;
  PBERVAL ldvlv_attrvalue;
  PBERVAL ldvlv_context;
  VOID    *ldvlv_extradata;
} LDAPVLVInfo, *PLDAPVLVInfo;