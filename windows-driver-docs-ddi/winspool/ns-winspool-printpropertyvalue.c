typedef struct {
  EPrintPropertyType ePropertyType;
  union {
    BYTE     propertyByte;
    PWSTR    propertyString;
    LONG     propertyInt32;
    LONGLONG propertyInt64;
    struct {
      DWORD  cbBuf;
      LPVOID pBuf;
    } propertyBlob;
  } value;
} PrintPropertyValue;