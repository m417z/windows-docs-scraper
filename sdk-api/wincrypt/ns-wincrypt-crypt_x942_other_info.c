typedef struct _CRYPT_X942_OTHER_INFO {
  LPSTR           pszContentEncryptionObjId;
  BYTE            rgbCounter[CRYPT_X942_COUNTER_BYTE_LENGTH];
  BYTE            rgbKeyLength[CRYPT_X942_KEY_LENGTH_BYTE_LENGTH];
  CRYPT_DATA_BLOB PubInfo;
} CRYPT_X942_OTHER_INFO, *PCRYPT_X942_OTHER_INFO;