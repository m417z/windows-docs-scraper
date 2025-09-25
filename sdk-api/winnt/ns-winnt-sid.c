typedef struct _SID {
  BYTE                     Revision;
  BYTE                     SubAuthorityCount;
  SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
#if ...
  DWORD                    *SubAuthority[];
#else
  DWORD                    SubAuthority[ANYSIZE_ARRAY];
#endif
} SID, *PISID;