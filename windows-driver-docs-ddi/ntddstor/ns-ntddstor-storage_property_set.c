typedef struct _STORAGE_PROPERTY_SET {
  STORAGE_PROPERTY_ID PropertyId;
  STORAGE_SET_TYPE    SetType;
  UCHAR               AdditionalParameters[1];
} STORAGE_PROPERTY_SET, *PSTORAGE_PROPERTY_SET;