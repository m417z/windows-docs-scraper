typedef struct _WINHTTP_EXTENDED_HEADER {
  union {
    PCWSTR pwszName;
    PCSTR  pszName;
  };
  union {
    PCWSTR pwszValue;
    PCSTR  pszValue;
  };
} WINHTTP_EXTENDED_HEADER, *PWINHTTP_EXTENDED_HEADER;