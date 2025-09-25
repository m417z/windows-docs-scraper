typedef struct _MIB_OPAQUE_INFO {
  DWORD dwId;
  union {
    ULONGLONG ullAlign;
    BYTE      rgbyData[1];
  };
} MIB_OPAQUE_INFO, *PMIB_OPAQUE_INFO;