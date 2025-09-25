typedef struct addrinfoexW {
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
  struct addrinfoexW *ai_next;
} ADDRINFOEXW, *PADDRINFOEXW, *LPADDRINFOEXW;