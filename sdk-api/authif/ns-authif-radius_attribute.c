typedef struct _RADIUS_ATTRIBUTE {
  DWORD            dwAttrType;
  RADIUS_DATA_TYPE fDataType;
  DWORD            cbDataLength;
  union {
    DWORD      dwValue;
    const BYTE *lpValue;
  };
} RADIUS_ATTRIBUTE, *PRADIUS_ATTRIBUTE;