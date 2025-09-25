typedef struct addrinfoex2A {
  int                 ai_flags;
  int                 ai_family;
  int                 ai_socktype;
  int                 ai_protocol;
  size_t              ai_addrlen;
  char                *ai_canonname;
  struct sockaddr     *ai_addr;
  void                *ai_blob;
  size_t              ai_bloblen;
  LPGUID              ai_provider;
  struct addrinfoex2A *ai_next;
  int                 ai_version;
  char                *ai_fqdn;
} ADDRINFOEX2A, *PADDRINFOEX2A, *LPADDRINFOEX2A;