typedef struct _SID {
  UCHAR                    Revision;
  UCHAR                    SubAuthorityCount;
  SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
#if ...
  ULONG                    *SubAuthority[];
#else
  ULONG                    SubAuthority[ANYSIZE_ARRAY];
#endif
} SID, *PISID;