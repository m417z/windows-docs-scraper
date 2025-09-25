typedef struct _BIDI_DATA {
  DWORD dwBidiType;
  union {
    BOOL             bData;
    LONG             iData;
    LPWSTR           sData;
    FLOAT            fData;
    BINARY_CONTAINER biData;
  } u;
} BIDI_DATA, *PBIDI_DATA, *LPBIDI_DATA;