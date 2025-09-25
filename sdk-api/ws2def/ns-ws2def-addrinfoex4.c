typedef struct addrinfoex4 {
  int                ai_flags;
  int                ai_family;
  int                ai_socktype;
  int                ai_protocol;
  size_t             ai_addrlen;
  PWSTR              ai_canonname;
  struct sockaddr    *ai_addr;
  void               *ai_blob;
  size_t             ai_bloblen;
  GUID               *ai_provider;
  struct addrinfoex4 *ai_next;
  int                ai_version;
  PWSTR              ai_fqdn;
  int                ai_interfaceindex;
  HANDLE             ai_resolutionhandle;
} ADDRINFOEX4, *PADDRINFOEX4, *LPADDRINFOEX4;