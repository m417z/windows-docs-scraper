typedef struct addrinfoex3 {
  int                ai_flags;
  int                ai_family;
  int                ai_socktype;
  int                ai_protocol;
  size_t             ai_addrlen;
  PWSTR              ai_canonname;
  struct sockaddr    *ai_addr;
  void               *ai_blob;
  size_t             ai_bloblen;
  LPGUID             ai_provider;
  struct addrinfoex3 *ai_next;
  int                ai_version;
  PWSTR              ai_fqdn;
  int                ai_interfaceindex;
} ADDRINFOEX3, *PADDRINFOEX3, *LPADDRINFOEX3;