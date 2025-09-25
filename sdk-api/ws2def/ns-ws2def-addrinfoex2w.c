typedef struct addrinfoex2W {
  int                 ai_flags;
  int                 ai_family;
  int                 ai_socktype;
  int                 ai_protocol;
  size_t              ai_addrlen;
  PWSTR               ai_canonname;
  struct sockaddr     *ai_addr;
  void                *ai_blob;
  size_t              ai_bloblen;
  LPGUID              ai_provider;
  struct addrinfoex2W *ai_next;
  int                 ai_version;
  PWSTR               ai_fqdn;
} ADDRINFOEX2W, *PADDRINFOEX2W, *LPADDRINFOEX2W;