typedef struct __WTS_PROPERTY_VALUE {
  unsigned short Type;
  union {
    ULONG ulVal;
    struct {
      ULONG size;
      WCHAR *pstrVal;
    } strVal;
    struct {
      ULONG size;
      char  *pbVal;
    } bVal;
    GUID  guidVal;
  } u;
} __WTS_PROPERTY_VALUE, WTS_PROPERTY_VALUE, *PWTS_PROPERTY_VALUE, __WRDS_PROPERTY_VALUE;