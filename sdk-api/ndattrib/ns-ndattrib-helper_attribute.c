typedef struct tagHELPER_ATTRIBUTE {
  LPWSTR         pwszName;
  ATTRIBUTE_TYPE type;
  union {
    BOOL          Boolean;
    char          Char;
    byte          Byte;
    short         Short;
    WORD          Word;
    int           Int;
    DWORD         DWord;
    LONGLONG      Int64;
    ULONGLONG     UInt64;
    LPWSTR        PWStr;
    GUID          Guid;
    LIFE_TIME     LifeTime;
    DIAG_SOCKADDR Address;
    OCTET_STRING  OctetString;
  };
} HELPER_ATTRIBUTE, *PHELPER_ATTRIBUTE;