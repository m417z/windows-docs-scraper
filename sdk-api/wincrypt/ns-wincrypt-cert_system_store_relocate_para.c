typedef struct _CERT_SYSTEM_STORE_RELOCATE_PARA {
  union {
    HKEY hKeyBase;
    void *pvBase;
  } DUMMYUNIONNAME;
  union {
    void    *pvSystemStore;
    LPCSTR  pszSystemStore;
    LPCWSTR pwszSystemStore;
  } DUMMYUNIONNAME2;
} CERT_SYSTEM_STORE_RELOCATE_PARA, *PCERT_SYSTEM_STORE_RELOCATE_PARA;