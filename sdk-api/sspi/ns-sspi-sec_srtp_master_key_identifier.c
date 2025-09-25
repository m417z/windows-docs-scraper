typedef struct _SEC_SRTP_MASTER_KEY_IDENTIFIER {
  unsigned char MasterKeyIdentifierSize;
  unsigned char MasterKeyIdentifier[ANYSIZE_ARRAY];
} SEC_SRTP_MASTER_KEY_IDENTIFIER, *PSEC_SRTP_MASTER_KEY_IDENTIFIER;