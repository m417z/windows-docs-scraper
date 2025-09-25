typedef struct _TOKEN_SOURCE {
  CHAR SourceName[TOKEN_SOURCE_LENGTH];
  LUID SourceIdentifier;
} TOKEN_SOURCE, *PTOKEN_SOURCE;