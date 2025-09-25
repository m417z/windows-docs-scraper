typedef struct HSTRING_HEADER {
  union {
    PVOID Reserved1;
#if ...
    char  Reserved2[24];
#else
    char  Reserved2[20];
#endif
  } Reserved;
} HSTRING_HEADER;