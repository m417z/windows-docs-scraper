typedef struct _STORAGE_IDENTIFIER {
  STORAGE_IDENTIFIER_CODE_SET CodeSet;
  STORAGE_IDENTIFIER_TYPE     Type;
  USHORT                      IdentifierSize;
  USHORT                      NextOffset;
  STORAGE_ASSOCIATION_TYPE    Association;
  UCHAR                       Identifier[1];
} STORAGE_IDENTIFIER, *PSTORAGE_IDENTIFIER;